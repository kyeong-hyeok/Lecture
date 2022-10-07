#include "Output.h"
#include "Filter.h"


void HISTOGRAM(unsigned char* Data, int wid, int hei, int max, char String[])
{
	FILE* fp;

	int    Cnt[PixRange] = { 0 };
	double NormalCnt[PixRange] = { 0 };
	unsigned char Output[PixRange][PixRange] = { 0 };

	unsigned char Name_Hist[50] = "Hist_";
	unsigned char Name_extension[10] = ".raw";

	int MaxCnt = 0;

	for (int i = 0; i < wid * hei; i++) // 빈도수 카운트
		Cnt[Data[i]]++;

	for (int i = 0; i < PixRange; i++) { // 빈도수가 가장 높은 화소값 찾기
		MaxCnt = MaxCnt < Cnt[i] ? Cnt[i] : MaxCnt;
	}
	for (int i = 0; i < PixRange; i++) // 정규화 : 최대 높이 255
		NormalCnt[i] = (double)Cnt[i] / MaxCnt * 255 + 0.5; 


	// 히스토그램
	for (int i=0; i<=255; i++ ) // x축
	{
		for (int j=255; j>255-NormalCnt[i]; j--) // y축 (좌측 하단 0,255)
		{
			Output[j][i] = 255;
		}
	}

	strcat(Name_Hist, String);
	strcat(Name_Hist, Name_extension);

	fopen_s(&fp, Name_Hist, "wb");
	fwrite(Output, sizeof(unsigned char), PixRange * PixRange, fp);
	fclose(fp);
}

void OutputHistogram(InputImage* in, OutputImage* out, HistModiImage* modi)
{
	unsigned char String[9][10] = { "Ori", "Plus" , "Minus" ,"Mul" ,"Div" ,"Equal", "EndIn", "PLDivi", "GamCo"};
	HISTOGRAM(in->Ori,    in->info.wid, in->info.hei, MaxVal, String[0]);
	HISTOGRAM(out->Plus,  in->info.wid, in->info.hei, MaxVal, String[1]);
	HISTOGRAM(out->Minus, in->info.wid, in->info.hei, MaxVal, String[2]);
	HISTOGRAM(out->Multi, in->info.wid, in->info.hei, MaxVal, String[3]);
	HISTOGRAM(out->Divi,  in->info.wid, in->info.hei, MaxVal, String[4]);
	HISTOGRAM(modi->Equal,in->info.wid, in->info.hei, MaxVal, String[5]);
	HISTOGRAM(modi->EIS,  in->info.wid, in->info.hei, MaxVal, String[6]);
	HISTOGRAM(out->PLDivi, in->info.wid, in->info.hei, MaxVal, String[7]);
	HISTOGRAM(out->GamCo, in->info.wid, in->info.hei, MaxVal, String[8]);
}
