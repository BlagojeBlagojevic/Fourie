//FURIJEOVA TRANSFORMACIJA OTPRILIKE

#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define PI 3.1415926
#define T  0.00001  //PERIOD ODABIRANJA
typedef struct compleksni   //DEFINICIJA KOMPLEKSNIH BROJEVA

{
	double realni;
	double imaginarni;
	
}kompleksni;
kompleksni fft(double Xn,int *mjerenje,kompleksni furiova_transformacija);//DEFINICIJA FURIOVE TRANSFORMACIJE
void inverznafft(kompleksni FT,int *mjerenje,double *Xn);              //DEFINICIJA INVERZNE FURIOVE TRANSFORMACIJE
kompleksni proizvod(kompleksni a,kompleksni b);                 //DEFINICIJA PROIZVOD KOMPLEKSNIH BROJEVA

int main(void)
{
	 kompleksni a,b,c,d,f;
	 kompleksni Prije_FT;
	 int mjerenje=0,mjerenje1=0,mjerenje2=0,mjerenje3=0,mjerenje4=0,mjerenje5=0;
	 int n=100,i=0,j=0;
	 double X_kordinate[1000],Y_kordinate[1000];
	 Prije_FT.imaginarni=0.0;
	 Prije_FT.realni=0.0;
	 b.imaginarni=0.0;
	 b.realni=0.0;
	 a.imaginarni=0.0;
	 a.realni=0.0;
	 d.imaginarni=0.0;
	 d.realni=0.0;
	 f.imaginarni=0.0;
	 f.realni=0.0;
	 while(1)
	 {
	 	double vrijednost=0;
	 	 double pomocna,pom111,pom222;
	 	//delay(20);
	 	//printf("\nDa li zelite da prekinete '1'\n");
	 	//scanf("%d",&n);
	 	if(n==1)
	 	break;
	 	else;
	 	pomocna=exp(T*(-mjerenje1))*sin(50*T*mjerenje1);
	 	a=fft(exp(T*(-mjerenje1)),&mjerenje1,a);
	 	X_kordinate[i++]=a.realni;
	 	Y_kordinate[j++]=a.imaginarni;n--;  //ZA CRTANJE
	 	b=fft(sin(50*T*mjerenje2),&mjerenje2,b);
	 	c=proizvod(a,b);
	 	d=fft(pomocna,&mjerenje3,d);
		inverznafft(c,&mjerenje4,&pom111);
		inverznafft(d,&mjerenje5,&pom222);
		if(pom111==pomocna)
		{
			printf("DA %f \n%f\nGreska%f\n", pom111,pom222,pom111-pom222);
			system("pause");
		}
		else
		{
			printf("Ne %f \n%f\nGreska\n%f\n", pom111,pom222,pom111-pom222);
			system("pause");	
		}
		if(pom111==0)
		break;	
	 }
	return 0;
}
kompleksni proizvod(kompleksni a,kompleksni b)
{
	double real,imag;
	kompleksni broj;
	broj.realni=a.realni*b.realni-a.imaginarni*b.imaginarni;
	broj.imaginarni=b.imaginarni*a.realni+a.imaginarni*b.realni;
	return broj;
	
}
kompleksni fft(double Xn,int *mjerenje,kompleksni furieova_transformacija)
{

	float a;
	a=2.0*PI*(*mjerenje);  //ugao u stepinima
	furieova_transformacija.realni=cos(a)*Xn;
	 furieova_transformacija.imaginarni=sin(a)*Xn;
	 *mjerenje=1+(*mjerenje);
	 //printf("Stvarni dio je:%f\n",Xn);
	 //printf("mjerenje je %d\nRealni koeficijent je: %f\nImaginarni Koeficijent je: %f",*mjerenje,furieova_transformacija.realni,furieova_transformacija.imaginarni);
	return furieova_transformacija;	
}
void inverznafft(kompleksni FT,int *mjerenje,double *Xn)
{
	kompleksni pom,pom1;
	pom.realni=cos(2*PI*(*mjerenje));
	pom.imaginarni=sin(2*PI*(*mjerenje));
	pom1=proizvod(FT,pom);                             //(URADJENO)TREBALO BI DODATI IF ZA POZITIVNE I NEGATIVNE MODUL *SIN(wt+atan(realn/im)) VALJDA
	//*Xn=sqrt(pow(pom1.realni,2)+pow(pom1.imaginarni,2));
	//if(pom1.realni>0)                                                        //MOZDA JE U STEPENIMA MOZDA
	*Xn=sqrt(pow(pom1.realni,2)+pow(pom1.imaginarni,2))*sin(2.0*PI*(*mjerenje)+atan(pom1.realni/pom1.imaginarni));
	//else
	//*Xn=(-1)*sqrt(pow(pom1.realni,2)+pow(pom1.imaginarni,2));
	//printf("Dio poslije fft:%f\n",*Xn);
	//return FT;
}
