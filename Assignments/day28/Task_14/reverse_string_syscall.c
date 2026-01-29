#include <linux/kernel.h>
#include <linux/syscalls.h>
#include <linux/uaccess.h>
#include <linux/string.h>

/*
 * Custom system call:
 * Takes a string from user space,
 * reverses it in kernel space,
 * and copies it back to user space.
 */

SYSCALL_DEFINE2(reverse_string,
                char __user *, input,
                char __user *, output)
{
    char kbuf[256];
    int len, i;

    /* Copy string from user space to kernel space */
    if (copy_from_user(kbuf, input, sizeof(kbuf)))
        return -EFAULT;

    kbuf[255] = '\0';   // Ensure null termination
    len = strlen(kbuf);

    /* Reverse string in kernel space */
    for (i = 0; i < len / 2; i++) {
        char temp = kbuf[i];
        kbuf[i] = kbuf[len - i - 1];
        kbuf[len - i - 1] = temp;
    }

    /* Copy reversed string back to user space */
    if (copy_to_user(output, kbuf, len + 1))
        return -EFAULT;

    return 0;
}
