#include <linux/module.h>
#include <linux/string.h>
#include <linux/fs.h>
#include <asm/uaccess.h>

//module attributes

MODULE_LICENSE("GPLv3");
MODULE_DESCRIPTION("Test Device Driver");
MODULE_AUTHOR("#rfm");

static char msg[100] = {0};
static short readPos=0;
static int times = 0;

//prototypes,else the structure initialization that follows fail

static int dev_open(struct inode *,struct file *);
static int dev_rls(struct inode *,struct file *);
static ssize_t dev_read(struct file *,char *,size_t,loff_t *);
static ssize_t dev_write(struct file *,const char *,size_t,loff_t *);

//sturcture containing callbacks
static struct file_operations fops = 
{
	.read = dev_read, //address data
	.open = dev_open, //address data
	.write = dev_write, //addres data
	.release = dev_rls //address data
};

int init_module(void)
{
int t = register_chrdev(95,"testDev",&fops);
	if(t<0) 
	printk(KERN_ALERT "testDev Device Registration Failed...\n");
	else
	printk(KERN_ALERT "testDev Device Registered...\n");
return t;
}

void cleanup_module(void)
{
	unregister_chrdev(95,"testDev");
}

static int dev_open(struct inode *inod,struct file *fil)
{
	times++;
	printk(KERN_ALERT,"Device opened %d times \n",times);
	return 0;
}
static ssize_t dev_read(struct file *filp,char *buff,size_t len,loff_t *off)
{
	short count = 0;
	while(len && (msg[readPos]!=0))
	{
		put_user(msg[readPos],buff++);
		count++;
		len--;
		readPos++;
	}
return count;
}

static  ssize_t dev_write(struct file *filp,const char *buff,size_t len,loff_t *off)
{
	short ind = len-1;
	short count =0;
	memset(msg,0,100);
	readPos=0;
	while(len>0)
	{
		msg[count++] = buff[ind--];
		len--;
	}
return count;
}

static int dev_rls(struct inode *inod,sturct file *fil)
{
	printk(KERN_ALERT"Device closed\n");
return 0;
}
