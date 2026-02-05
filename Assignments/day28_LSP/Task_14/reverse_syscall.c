#include <linux/kernel.h>
#include <linux/syscalls.h>
#include <linux/uaccess.h>
#include <linux/slab.h>

SYSCALL_DEFINE3(reverse_string,
    char __user *, user_input,
    char __user *, user_output,
    int, len)
{
    char *kbuf;
    int i;

    if (len <= 0)
        return -EINVAL;

    kbuf = kmalloc(len + 1, GFP_KERNEL);
    if (!kbuf)
        return -ENOMEM;

    if (copy_from_user(kbuf, user_input, len)) {
        kfree(kbuf);
        return -EFAULT;
    }

    kbuf[len] = '\0';

    for (i = 0; i < len / 2; i++) {
        char tmp = kbuf[i];
        kbuf[i] = kbuf[len - i - 1];
        kbuf[len - i - 1] = tmp;
    }

    if (copy_to_user(user_output, kbuf, len + 1)) {
        kfree(kbuf);
        return -EFAULT;
    }

    kfree(kbuf);
    printk(KERN_INFO "reverse_string syscall executed\n");

    return 0;
}
