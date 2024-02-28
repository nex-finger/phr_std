/* ************************************************************************** */
/*
 * 関数名   StdChr_Isalpha
 * 機能     文字が英文字（A～Z、a～z）か検査
 * 引数     型          変数名          説明
 *          uint32t     aC              対象文字
 * 戻り値   uint32t     tRet
 * 説明     文字aCが英文字（A～Z、a～z）なら真（0以外の数）を返す
 *          文字aCが英文字以外なら偽（0）を返す
 */
/* ************************************************************************** */
uint32t StdChr_Isalpha(uint32t aC)
{
    /* 戻り値の初期化 */
    uint32t tRet = DEF_STDCHR_0;

    /* ここに実装してください。 */
    if(StdChr_Isupper(aC)) {
        return 0x01;
    } else if(StdChr_Islower(aC)) {
        return 0x02;
    }   else {
        return 0x00;
    }

    return tRet;
}