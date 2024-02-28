/* ************************************************************************** */
/*
 * �֐���   StdChr_Isalpha
 * �@�\     �������p�����iA�`Z�Aa�`z�j������
 * ����     �^          �ϐ���          ����
 *          uint32t     aC              �Ώە���
 * �߂�l   uint32t     tRet
 * ����     ����aC���p�����iA�`Z�Aa�`z�j�Ȃ�^�i0�ȊO�̐��j��Ԃ�
 *          ����aC���p�����ȊO�Ȃ�U�i0�j��Ԃ�
 */
/* ************************************************************************** */
uint32t StdChr_Isalpha(uint32t aC)
{
    /* �߂�l�̏����� */
    uint32t tRet = DEF_STDCHR_0;

    /* �����Ɏ������Ă��������B */
    if(StdChr_Isupper(aC)) {
        return 0x01;
    } else if(StdChr_Islower(aC)) {
        return 0x02;
    }   else {
        return 0x00;
    }

    return tRet;
}