
void scheduler(void)
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

