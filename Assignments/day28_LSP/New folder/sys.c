#include <linux/kernel.h>
#include <linux/syscalls.h>
#include <linux/uaccess.h>
#include <linux/slab.h>

SYSCALL_DEFINE3(reverse_string,
                const char __user *, input,
                char __user *, output,
                size_t, len)
{
    char *kbuf;
    int i;

    kbuf = kmalloc(len, GFP_KERNEL);
    if (!kbuf)
        return -ENOMEM;

    if (copy_from_user(kbuf, input, len)) {
        kfree(kbuf);
        return -EFAULT;
    }

    for (i = 0; i < len / 2; i++) {
        char temp = kbuf[i];
        kbuf[i] = kbuf[len - i - 1];
        kbuf[len - i - 1] = temp;
    }

    if (copy_to_user(output, kbuf, len)) {
        kfree(kbuf);
        return -EFAULT;
    }

    kfree(kbuf);
    return 0;
}
