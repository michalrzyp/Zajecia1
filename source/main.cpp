#include<Windows.h>
#include<stdio.h>
int wybierz(int x, int odp);
int WINAPI WinMain(HINSTANCE hinstance, HINSTANCE hPrevinstance, PSTR szCmdLIne, int iCmdShow)
{
	int odp, r = 20;
	char pppp[50], wynik[50];
	MessageBox(0, "Wybierz liczbe z zakresu 1-40", "Gra", MB_OK);
	for (int i = 0; i < 5; i++)
	{
		sprintf_s(pppp, "Czy twoja liczba jest wieksza od %d?", r);
		odp = MessageBox(0, pppp, "Gra", MB_YESNO);
		if (odp == IDNO)
		{
			r -= wybierz(i, odp);
		}
		else
		{
			r += wybierz(i, odp);
		}
	}
	if ((r - 1) % 5 == 1)
	{
		r -= 1;
		sprintf_s(pppp, "Czy twoja liczba jest wieksza od %d?", r);
		odp = MessageBox(0, pppp, "Gra", MB_YESNO);
		odp == IDYES ? r += 1 : 0;
	}
	sprintf_s(wynik, "Czy twoja liczba to %d?", r);
	odp=MessageBox(0, wynik, "Gra", MB_YESNO);
	odp == IDYES ? MessageBox(0, "Jestem dobry!", "Zwyciestwo", MB_OK) : MessageBox(0, "Klamiesz!", "Zwyciestwo", MB_ICONWARNING);
	return 0;
}
int wybierz(int x, int odp)
{
	int y = 0;
	switch (x)
	{
	case 0: y = 10; break;
	case 1:	y = 5; break;
	case 2: odp == IDYES ? y = 3 : y = 2; break;
	case 3: y = 1; break;
	case 4: odp == IDYES ? y = 1 : y = 0; break;
	default:
		break;
	}
	return y;
}