//code from https://www.cnblogs.com/JVxie/p/4854719.html

Tarjan(u)//marge��findΪ���鼯�ϲ������Ͳ��Һ���
{
    for each(u,v)    //��������u�ӽڵ�v
    {
        Tarjan(v);        //�������±���
        marge(u,v);    //�ϲ�v��u��
        ���v�����ʹ�;
    }
    for each(u,e)    //�������к�u��ѯ�ʹ�ϵ��e
    {
        ���e�����ʹ�;
        u,e�������������Ϊfind(e);
    }
}

