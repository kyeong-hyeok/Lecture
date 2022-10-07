#include "Filter.h"
#include "Output.h"

void ArithmeticVer1(UInt8 *ori, Int32 wid, Int32 hei, OutputImage* out)
{
    unsigned char String[7][10] = { "Ori", "Plus" , "MinZus" ,"Mul" ,"Div", "PLDivi", "GamCo" };

    unsigned char PlusLut[PixRange], MinusLut[PixRange], MultiLut[PixRange], DiviLut[PixRange] , PLDiviLut[PixRange], GamCoLut[PixRange];

    for (int Idx = 0; Idx < PixRange; Idx++)                                  
    {
        PlusLut [Idx] = Clip3(0, 255, (int)(Idx + alpha+0.5));
        MinusLut[Idx] = Clip3(0, 255, (int)(Idx - beta+0.5));
        MultiLut[Idx] = Clip3(0, 255, (int)(Idx * gamma+0.5));
        DiviLut[Idx] = Clip3(0, 255, (int)(Idx / delta+0.5));
    }

    for (int cur = 0; cur < wid * hei; cur++) // 전체화소값
    {
        out->Plus[cur] = PlusLut[ori[cur]];
        out->Minus[cur] = MinusLut[ori[cur]];
        out->Multi[cur] = MultiLut[ori[cur]];
        out->Divi[cur] = DiviLut[ori[cur]];
       
    }

    ImageOutput(out->Plus,  wid, hei, String[1]);
    ImageOutput(out->Minus, wid, hei, String[2]);
    ImageOutput(out->Multi, wid, hei, String[3]);
    ImageOutput(out->Divi, wid, hei, String[4]);

}

unsigned char Clip3(Int32 minVal, Int32 maxVal, Int32 curVal) // Clipping
{
    return curVal < minVal ? minVal : curVal > maxVal ? maxVal : curVal;
}
