/*
	author:
	1.Joyita Hossain   
	2.Md Forhad Hossain 

	last modified: March __, 2014
*/
/*pic f1 100 px  100px*/
# include "iGraphics.h"
#include<time.h>																									/*for random call*/
#include<stdlib.h>	/*for exit(0)*/
#include<string.h>
int boat_x, boat_y,b=0,by,l=0;																						/*for drawing boat*/
int px1,px2,pxn1,pxn2,pxnn1,pxnn2,pxnnn1,pxnnn2;																	/*for positining from two side of the sea :D*/
int front1=1,finish=1;																								/*for multiple screen  1=play,cotinue,howto  0=game page*/
int a,an,ann,annn,an2,ann2,annn2,vn,firstpos[]={0,128,256},secondpos[]={64,192,320};												/*for randomly calling fishes and position of the fishesh*/
int m=0,/*m is used for keeping the caught fish up ;) */point=0,/*for score */v1,v2;							   /*for jelly fish */
int neg;//useless
//int cong=-1;//for show position message
int jj=0;//for resume user name

char high[10];
int highscore=0;

char player[100],newplayer[100],highscore1[10],highscore2[10],highscore3[10];

char str[10],tim[10];int ttime=-1;																			/*for showing time*/
char lif[10];

char resum[100];

FILE *fp, *hgs,*na;										//for file continue 
typedef struct xx{
	char hplayer[80];
	
	int hscore;
}hgsc;												//for highScores
hgsc hplrs[3]={
	"None",0,
	"None",0,
	"None",0
};																	

int kbrd=0;


int save=0;																											//useless
int name=0;																											//still useless
int how=0,h=0,hi=0;																										//for how to play 
char nam[100];

int len=0,le=0,input_name_screen_to_gamescreen=0; // for input name


int nameshow=1;


int gamescreen=0;


void timetrack(void)																								//every sec will be called
{
	if(finish>0)																									//          ""
	{
	}
	else{																											//          ""
		ttime++;
	
	} 																									//          ""
	itoa(ttime,tim,10);
}																													//          ""



void fishmove()																										/*for fishes from left to wright*/
{
	px1+=3;
	v1+=8;
	if(pxn1<964) pxn1+=3;
	else{pxn1=-300;an=rand()%3;}
	if(pxnn1<964) pxnn1+=3;
	else{pxnn1=-600;ann=rand()%3;}																					//           ""
	if(pxnnn1<964) pxnnn1+=3;
	else{pxnnn1=-900;annn=rand()%3;}
}																													//           ""



void fishmove2()																									/*for fishes from right to left*/
{
	px2-=3;
	v2-=8;
	if(pxn2>-64)pxn2-=3;
	else{pxn2=1200;an2=rand()%3;}
	if(pxnn2>-64) pxnn2-=3;
	else{pxnn2=1500;ann2=rand()%3;}
	if(pxnnn2>-64) pxnnn2-=3;
	else{pxnnn2=1800;annn2=rand()%3;}
	
}																													/*             ""             */
void randomcall(){																									/*      changes after   6.5 sec     */
	px1=-64;
	px2=964;
	a=rand()%3;
}
void borshidraw(){																									/*borshii up down  result count live count */

	itoa(point,str,10);
	iSetColor(0, 0, 0);
	if(by>=0&&l==0){
		iFilledRectangle(boat_x, by-=5, 1, boat_y+30-by);
		if(by==0) l=1;
	}
	 if(l==1&&by!=boat_y+30){
		iFilledRectangle(boat_x, by+=5, 1, boat_y+30-by);
	}
	iShowBMP(boat_x-32, by-32, "hook.bmp");
	if(px1-boat_x+15<65&&px1-boat_x+15>=0){
		if(by-30-firstpos[a]<65&&by-30-firstpos[a]>0){
			px1=2000;
			m=1;
			l=1;
			point++;
		}
	}
	if(boat_x-30-px2<65&&boat_x-30-px2>=0){
		if(by-30-secondpos[a]<65&&by-30-secondpos[a]>=0){
			px2=2000;
			m=1;
			l=1;
			point++;
		}
	}
	if(pxn1-boat_x+15<65&&pxn1-boat_x+15>=0){
		if(by-30-firstpos[an]<65&&by-30-firstpos[an]>=0){
			pxn1=-300;
			m=1;
			l=1;
			point++;
		}
	}
	if(boat_x-30-pxn2<65&&boat_x-30-pxn2>=0){
		if(by-30-secondpos[an2]<65&&by-30-secondpos[an2]>=0){
			pxn2=1200;
			m=1;
			l=1;
			point++;
		}
	}
	if(pxnn1-boat_x+15<65&&pxnn1-boat_x+15>=0){
		if(by-30-firstpos[ann]<65&&by-30-firstpos[ann]>=0){
			pxnn1=-600;
			m=1;
			l=1;
			point++;
		}
	}
	if(boat_x-30-pxnn2<65&&boat_x-30-pxnn2>=0){
		if(by-30-secondpos[ann2]<65&&by-30-secondpos[ann2]>=0){
			pxnn2=1500;
			m=1;
			l=1;
			point++;
		}
	}
	if(pxnnn1-boat_x+15<65&&pxnnn1-boat_x+15>=0){
		if(by-30-firstpos[annn]<65&&by-30-firstpos[annn]>=0){
			pxnnn1=-900;
			m=1;
			l=1;
			point++;
		}
	}
	if(boat_x-30-pxnnn2<65&&boat_x-30-pxnnn2>=0){
		if(by-30-secondpos[annn2]<65&&by-30-secondpos[annn2]>=0){
			pxnnn2=1800;
			m=1;
			l=1;
			point++;
		}
	}
	if(v1-boat_x+15<65&&v1-boat_x+15>=0){
		if(by-30-firstpos[vn]<65&&by-30-firstpos[vn]>=0){
			v1=2000;
			m=2;
			l=1;
			point-=1;
		}
	}
	if(boat_x-30-v2<65&&boat_x-30-v2>=0){
		if(by-30-secondpos[vn]<65&&by-30-secondpos[vn]>=0){
			v2=2000;
			m=2;
			l=1;
			point-=1;
	
		}
	}
	

	
}																								/*finish of barshi draw()*/

void pointfish(){																				/*random call jelly fish*/
	v1=0;v2=900;
	vn=rand()%3;
}




void printboard()																				/*for highscores,how to play ,gameover screen*/
{
	
	int i=1;
	int abx,aby,cx,cy;
	for(abx=0;abx<=600;abx+=100){
		for(aby=0;aby<=900;aby+=50){
			if(!(i%2))iSetColor(99,99,99);
			else iSetColor(55,55,55);

			i++;
			iFilledRectangle(aby,abx,100,100);
		}
	}
}


int fo=0;                              // for giving condition to the score screen ;)
int foo=0;
void iDraw() {	
	iClear();


	if(ttime>=30){
		iClear();
		finish=2;
		front1=2;
	}
	 if(ttime<30 && (input_name_screen_to_gamescreen==1 || front1==0 ||jj==1) ){	/*if front1==0        then         gamescreen or if lee==1 then from input name to gamescreen*/

		na=fopen("name.txt","w");
		fprintf(na,"%s",player);
		fclose(na);
		gamescreen=1;
		iSetColor(0,162,232);									 //making board
		iFilledRectangle(0,418,900,182);
		iSetColor(153,217,234);									 //making board
		iFilledRectangle(0,0,900,418);
		iSetColor(42,255,0);
		
		iFilledRectangle(0,570,45,20);

		iSetColor(0,0,0);	
		iText(2,555,tim);											//for showing time
		iSetColor(42,255,0);
		iFilledRectangle(0,570,45,20);
		if(jj==1)
		{
			iText(663,550,"Now playing");
			iText(755,550,resum);}
			iSetColor(0,0,0);
			iText(2,575,"HOME");			//for show back to home option
	
			iText(663,550,"Now playing");
			iText(755,550,newplayer);

			iSetColor(0,0,0);
		if(ttime<7){						//for show instruction
			iSetColor(0,0,0);
			iText(309,291,"TIME LIMIT 30 SECONDS",GLUT_BITMAP_TIMES_ROMAN_24);
			iText(255,238,"CATCH RED FISH AS MUCH YOU CAN",GLUT_BITMAP_TIMES_ROMAN_24);
			iText(120,215,"AVOID CATCHING GELLY FISH TO AVOID NEGATIVE POINT",GLUT_BITMAP_TIMES_ROMAN_24);
		}
		iShowBMP(boat_x, boat_y-1, "boat.bmp");
		iShowBMP(px1,firstpos[a],"f0.bmp");
		iShowBMP(px2,secondpos[a],"f6.bmp");
		iShowBMP(pxn1,firstpos[an],"f0.bmp");
		iShowBMP(pxn2,secondpos[an],"f6.bmp");
		iShowBMP(pxnn1,firstpos[ann],"f0.bmp");
		iShowBMP(pxnn2,secondpos[ann],"f6.bmp");
		if(vn!=a){
			iShowBMP(v1,firstpos[vn],"jelly.bmp");
			iShowBMP(v2,secondpos[vn],"jelly.bmp");}
		if(b==1){
			borshidraw();
		}
		if(m==1){										//for fish up
			iShowBMP(boat_x-20,by-100,"f11.bmp");
			if(by==boat_y+30) m=0;
		}
		if(m==2){
			iShowBMP(boat_x-20,by-100,"jelly.bmp");
			if(by==boat_y+30) m=0;
		}
		iSetColor(0, 0, 0);									//for score show
		iText(430,570,"Score:",GLUT_BITMAP_TIMES_ROMAN_24);
		iRectangle(430, 520, 50, 30);
		iRectangle(428, 522, 50, 30);
		iText(438 ,530,str);}	

		else  if(front1==1){																			/*if front1==1          then       homescreen*/
			iShowBMP(0,0,"front.bmp");
			iSetColor(255,255,255);
			iText(370,440,"PLAY",GLUT_BITMAP_TIMES_ROMAN_24);
			iText(74,330,"                                               CONTINUE                             ",GLUT_BITMAP_TIMES_ROMAN_24);
			iText(340,230,"HOW TO PLAY",GLUT_BITMAP_TIMES_ROMAN_24);
			iText(345,130,"HIGH SCORES",GLUT_BITMAP_TIMES_ROMAN_24);
			iText(383,54,"EXIT",GLUT_BITMAP_TIMES_ROMAN_24);
	
		}
		 if(front1==2){																		//for score 
			printboard();
			iSetColor(255,0,42);

			iText(386,441,newplayer,GLUT_BITMAP_TIMES_ROMAN_24);
			iSetColor(0,0,0);
			iFilledRectangle(250,340,400,60);
			iSetColor(255,255,255);
			iText(254,362,"YOUR SCORE IS ",GLUT_BITMAP_TIMES_ROMAN_24);
			iText(534,362,str,GLUT_BITMAP_TIMES_ROMAN_24);
			iSetColor(42,255,0);
			iFilledRectangle(0,570,45,20);
			iSetColor(0,0,0);
			iText(2,575,"HOME");
		}
		else  if(input_name_screen_to_gamescreen==0 && front1==3){
			printboard();
			iSetColor(42,255,0);
			iFilledRectangle(0,570,45,20);
			iSetColor(0,0,0);
			iText(2,575,"HOME");
			iSetColor(0,0,0);
			iFilledRectangle(250,340,400,60);
			iSetColor(255,255,255);
			iText(254,362,"ENTER YOUR NAME:",GLUT_BITMAP_TIMES_ROMAN_24);
			iText(534,362,nam,GLUT_BITMAP_TIMES_ROMAN_24);
			//kbrd=0;
		 }
		else  if(front1==4)                  //for highscore show;
		 {
			 printboard();
			/* iSetColor(42,255,0);
			iFilledRectangle(0,570,45,20);
			iSetColor(0,0,0);
			iText(2,575,"HOME");*/
			 iSetColor(0,0,0);
			iFilledRectangle(250,340,400,60);
		 
		 
			iSetColor(42,255,0);
			iFilledRectangle(830,570,45,20);
			iSetColor(255,255,255);
			iText(835,575,"HOME");	

			iFilledRectangle(250,300,400,200);
			iSetColor(255,0,0);


			iText(300,355,hplrs[2].hplayer);         //355,400,445
			iText(500,345,highscore3);

			iText(300,400,hplrs[1].hplayer);
			iText(500,400,highscore2);
			iText(300,445,hplrs[0].hplayer);
			iText(500,445,highscore1);

		/*iSetColor(255,255,255);
		iText(254,362,"HIGH SCORE: ",GLUT_BITMAP_TIMES_ROMAN_24);
		iText(534,362,high,GLUT_BITMAP_TIMES_ROMAN_24);*/
		/*iSetColor(42,255,0);
		iFilledRectangle(0,570,45,20);
		iSetColor(0,0,0);
		iText(2,575,"HOME");*/
		
		}

		else if(how==1){/*   how==1    it print board and show how to play*/
			iClear();
			printboard();
			/*iSetColor(42,255,0);
			iFilledRectangle(0,570,45,20);
			iSetColor(42,255,0);
			iSetColor(255,255,255);		
			iText(2,575,"HOME");
			iSetColor(255,255,255);*/		
			iSetColor(42,255,0);
			iFilledRectangle(830,570,45,20);
			iSetColor(255,255,255);
			iText(835,575,"HOME");										//show life
		
			iText(272,389,"CATCH RED FISH AS MUCH YOU CAN",GLUT_BITMAP_TIMES_ROMAN_24);
			iText(145,340,"AVOID CATCHING GELLY FISH TO AVOID NEGATIVE POINT",GLUT_BITMAP_TIMES_ROMAN_24);
			iText(131,255,"USE LEFT OR RIGHT ARROW BUTTON TO MOVE THE BOAT",GLUT_BITMAP_TIMES_ROMAN_24);		
	}	
}

void iMouseMove(int mx, int my) {	
}
void iMouse(int button, int state, int mx, int my) {
	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
		b=1;
		printf("%d %d\n",mx,my);
		if(front1==1 && mx>350 && mx<450 &&my>400 && my<500) //for play option		
		{
			front1=3;		
			kbrd=1;
		}

		if(front1==1 && mx>300 && mx<500 && my>300 && my<400)          //continue option (for resume)
		{
			na=fopen("name.txt","r");
			if(na){
			fscanf(na,"%s",newplayer);
			fclose(na);
			}
			jj=1;
			if(finish==2)front1=1;
			front1=0;
			fp=fopen("fish.txt","r");
			fscanf(fp,"%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d",&ttime,&px1,&px2,&pxn1,&pxn2,&pxnn1,&pxnn2,&pxnnn1,&pxnnn2,&a,&an,&ann,&annn,&vn,&m,&point,&v1,&v2,&boat_x, &boat_y,&save,&finish,&highscore);
			itoa(point,str,10);

			fclose(fp);
			finish=0;
		}

		if(front1==1 && mx>356 && mx<515 && my>227 && my<252){how=1;}		//when home screen e how to er upr button pres				
		if(how==1  && mx>830 && mx<873 && my>572 && my<594){how=0;front1=1;} //how to play
		if(hi==1  && mx>830 && mx<873 && my>572 && my<594)               //high score ;)
		{
			hi=0;
			front1=1;
		}
		if(front1==1 && mx>384 && mx<432 && my>59 && my<76)
			
		{
			exit(0);						//  to exit from home screen      
		}


		if(mx>0 && mx<45 &&my>570 && my<590) //at the time of back to home from game screen
		{
			h=1;//useless
			kbrd=1;
			jj=0;						
			int i;								

			for( i =0;i<3;i++)
			{
				//if(point==hplrs[i].hscore && strcmp(newplayer,hplrs[i].hplayer)==0){}
				


				 if(point > hplrs[i].hscore)
				{
					int j;
					for(j=2;j>=0;j--)
					{
						if(i==j)
						{
							hplrs[j].hscore=point;
							strcpy(hplrs[j].hplayer,newplayer);
							break;
						}
						else
						{
							hplrs[j].hscore=hplrs[j-1].hscore;
							strcpy(hplrs[j].hplayer,hplrs[j-1].hplayer);
						}
					}
							//cong=i;
					break;
				}
				//}
						
			}



			hgs=fopen("highscores.txt","w");
			for(i=0;i<3;i++)
			{
				fprintf(hgs,"%d\n %s\n",hplrs[i].hscore,hplrs[i].hplayer);
			}
			fclose(hgs);
			input_name_screen_to_gamescreen=0;
			how=0;                  //if how ==1 then     print board and show the instruction
			front1=1;//home screen
			save=1;			
		//	if(gamescreen==1){
			fp=fopen("fish.txt","w");
			fprintf(fp,"%d \n%d \n%d \n%d \n%d \n%d \n%d \n%d \n%d \n%d \n%d \n%d \n%d \n%d \n%d \n%d \n%d \n%d \n%d \n%d \n%d \n%d \n%d",ttime,px1,px2,pxn1,pxn2,pxnn1,pxnn2,pxnnn1,pxnnn2,a,an,ann,annn,vn,m,point,v1,v2, boat_x, boat_y,save,finish,highscore);
			fclose(fp);
		//	}
			ttime=-1;                               // start from the first		
			finish=1;
			srand(time(NULL));
			boat_x = 400;
			boat_y = 385;
			by=boat_y +30;
			pxn1=-300;
			pxn2=1200;
			pxnn1=-600;
			pxnnn1=-900;
			pxnnn2=1800;
			pxnn2=1500;
			v1=0;
			v2=900;
			vn=rand()%3;
			an=rand()%3;
			ann=rand()%3;
			point=0;
			//negpoint=5;	
		}
		
				
		if(front1==1 && mx>344 && mx<505 && my>129 && my<149){     //for high score
			
			front1=4;
			hi=1;
			itoa(hplrs[0].hscore,highscore1,10);
			itoa(hplrs[1].hscore,highscore2,10);
			itoa(hplrs[2].hscore,highscore3,10);
				
		}       

		l=0;	
	}
	if (button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN) {
		//place your codes here	
	}
}

void iKeyboard(unsigned char key) {	
	if(front1==3 && kbrd==1){    //for show the name		
		if(key == '\r'){
				kbrd=0;
				nam[le]='\0';
				strcpy(player,nam);
				strcpy(newplayer,player);
				while(le--)
				{
					nam[le]=0;
				}
				le=0;
				input_name_screen_to_gamescreen=1;
				finish=0;				
		}
		else
		{
			input_name_screen_to_gamescreen=0;
			nam[le]=key;
			len=len*10 + (key-'0');
			le++;
		}

		nameshow=0;
		//kbrd=0;
	}
	if (key == 'x') {
		exit(0);
	}
}

void iSpecialKeyboard(unsigned char key) {
	if (key == GLUT_KEY_END) {
		exit(0);
	}
	if (key == GLUT_KEY_LEFT) {										// for boat move
		if(boat_x>0)
		boat_x-=5;
	}
	if (key == GLUT_KEY_RIGHT) {
		if(boat_x<895)
		boat_x+=5;
	}
}

void initialcall()														//initial condition
{
	srand(time(NULL));
	boat_x = 400;
	boat_y = 385;
	by=boat_y +30;
	pxn1=-300;
	pxn2=1200;
	pxnn1=-600;
	pxnnn1=-900;
	pxnnn2=1800;
	pxnn2=1500;
	v1=0;
	v2=900;
	vn=rand()%3;
}
int main() {
	initialcall();
	int i;

		hgs=fopen("highscores.txt","r");
		if(hgs)
		{
			for(i=0;i<3;i++)
			{
				fscanf(hgs,"%d %s",&hplrs[i].hscore,hplrs[i].hplayer);
			}
			fclose(hgs);
							
		}	
	iSetTimer(6500 ,randomcall);
	iSetTimer(3250, pointfish);
	iSetTimer(10,fishmove);
	iSetTimer(10,fishmove2);
	iSetTimer(1000,timetrack);
	iInitialize(900, 600, "fIsHiNg fIgHt");
	return 0;
}
