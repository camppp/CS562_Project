push:
    # check if stack is full
    cmp sp, #64
    b.eq stack_full

    # store the value in the stack
    str w0, [sp, #-4]!

    # update the stack pointer
    sub sp, sp, #4

    bx lr

stack_full:
    # handle stack overflow
    mov r0, #-1
    bx lr

pop:
    # check if stack is empty
    cmp sp, #64
    b.eq stack_empty

    # load the value from the stack
    ldr w0, [sp, #4]

    # update the stack pointer
    add sp, sp, #4

    bx lr

stack_empty:
    # handle stack underflow
    mov r0, #-1
    bx lr

peek:
    # check if stack is empty
    cmp sp, #64
    b.eq stack_empty

    # load the value from the stack
    ldr w0, [sp, #4]

    bx lr
