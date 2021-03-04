
void scheduler(void)
{
  struct proc *p;

  for(;;){
    // ��ÿ��ִ��һ������֮ǰ����Ҫ����sti()��������CPU���ж�
    sti();

    // �������̱��ҵ�һ������ִ��
    //#####����Ҫ��ȫ�Ĵ���1 // ��ȡ���̱��������������CPU���Ľ��̱�
    for(p = ptable.proc; p < &ptable.proc[NPROC]; p++){
      // ������̵�״̬Ϊ�������У����Թ�
      if(p->state != RUNNABLE)
        continue;

      // �л���ѡ��Ľ��̣��ͷŽ��̱����������̽���ʱ�������»�ȡ
      //#####����Ҫ��ȫ�Ĵ���2
      switchuvm(p);
      p->state = RUNNING;
      //#####����Ҫ��ȫ�Ĵ���3
      switchkvm();

      // Process is done running for now.
      // It should have changed its p->state before coming back.
      //#####����Ҫ��ȫ�Ĵ���4
    }
    //#####����Ҫ��ȫ�Ĵ���5
  }
}

