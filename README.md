实验七指导书

对于单个CPU来说，scheduler是最主要的函数。当CPU初始化之后，即调用scheduler()，循环从进程队列中选择一个进程执行；当进程结束时，将控制权通过swtch()移交给scheduler。现给你一份待补全的代码，共有五个空需要补全，而本题给了你七个选项，你需要从这七个选项中分别选出五处待补全代码中所需要补充的代码。请注意；在提交代码时，待补充代码处需补入相应的代码，而不是A、B、C、D、E、F、G这些选项字母。

//代码开始


void
scheduler(void)
{

  struct proc *p;
 
  for(;;){
  
    // 在每次执行一个进程之前，需要调用sti()函数开启CPU的中断
    sti();
    
    // 遍历进程表找到一个进程执行
    //#####你需要补全的代码1 // 获取进程表的锁，避免其他CPU更改进程表
    for(p = ptable.proc; p < &ptable.proc[NPROC]; p++){
      // 如果进程的状态为不可运行，则略过
      if(p->state != RUNNABLE)
        continue;

      // 切换到选择的进程，释放进程表锁，当进程结束时，再重新获取
      //#####你需要补全的代码2
      switchuvm(p);
      p->state = RUNNING;
      //#####你需要补全的代码3
      switchkvm();

      // Process is done running for now.
      // It should have changed its p->state before coming back.
      //#####你需要补全的代码4
    }
    //#####你需要补全的代码5
  }
}

//代码结束

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
