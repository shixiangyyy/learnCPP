//��̬��������������Ϊ�麯����Ҳ�����Ա�const��volatile�ؼ�������
//���static�����������κζ��������ʵ������˼���virtualҲ��û�������
//�麯������vptr��vtable���д���vptr��һ��ָ�룬����Ĺ��캯�������ɣ�ֻ��ʹ��thisָ��
//���з��ʡ�����̬��Ա����û��thisָ�룬����޷�����vptr
virtual static void fun(){}
static void fun() const{}