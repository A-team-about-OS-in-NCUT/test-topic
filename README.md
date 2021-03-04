实验七指导书

对于单个CPU来说，scheduler是最主要的函数。当CPU初始化之后，即调用scheduler()，循环从进程队列中选择一个进程执行；当进程结束时，将控制权通过swtch()移交给scheduler。现给你一份待补全的代码,
即proc.c，此代码共有五个空需要补全，而本题给了你七个选项，你需要从这七个选项中分别选出五处待补全代码中所需要补充的代码。请注意；在提交代码时，待补充代码处需补入相应的代码，而不是A、B、C、D、E、F、G这些选项字母。

//
选项：

A.release(&ptable.lock);

B.proc = p;

C.acquire(&ptable.lock);

D.swtch(&cpu->scheduler, proc->context);

E.proc = 0;

F.acquire(ptable.lock);

G.proc++;

//
