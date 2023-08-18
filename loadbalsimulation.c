#include<stdio.h>
#include<string.h>
#include<conio.h>
double peakwattage(int n, double wattage[])
{
double peak;
peak = 0;
int i;
for (i = 0; i <= n - 1; i++)
{
peak = peak + wattage[i];
}
return peak;
}

double avgwattage(double peak)
{
double avg;
avg = (peak + 0) / 2;
return avg;
}

double Loadbalancer(double peak, double avg)
{
double balancer;
balancer = peak - avg;
return balancer;
}
void wc()
{
    int n;
    struct appliance{
        
        char name[100][100];
        char name1[20];
        double wattage[100];
        int quantity[100];
        
    };
    struct appliance ap,*pap;
    pap=&ap;
//stores no of appliances/
printf("enter the number of aplliances: ");
scanf("%d",&n);
char name[n][100],name1[20];
//stores the name of aplliance/
printf("Enter the name of appliance: ");
for(int i=0;i<n;i++)
 {
     scanf("%s", pap->name[i]);
     printf("%s\n",pap->name[i]);
     
 }
 //stores the wattage of the appliance/
 /*in general the wattage of fan=55watts
    tube light=50watts
    AC=1500watts
    Geyser=2000watts*/
printf("Enter the wattage of appliance: ");
for(int i=0;i<n;i++)
 {
     scanf("%lf",&pap->wattage[i]);
 }
 
 printf("Enter the number of quantity required: ");
 for(int i=0;i<n;i++)
 {
 scanf("%d",&pap->quantity[i]);
 }
for (int i=0;i<n;i++)
 {
    pap->wattage[i]=pap->quantity[i]*pap->wattage[i];
    printf("The wattage of ");
    printf("%s",pap->name[i]);
    printf(" is");
    printf("%lf\n",pap->wattage[i]);
   
 }
double peak,avg,balancer;
 peak=peakwattage(n,pap->wattage);
 avg=avgwattage(peak);
 balancer=Loadbalancer(peak,avg);
 printf("The peak wattage in the house is: %lf\n",peak);
 printf("Average wattage used in house is: %lf\n",avg);
 printf("The load balancer need to be maintained is of %lf\n",balancer);
}
struct appliance{
    char app[100];
};
struct circuit{
    struct appliance x[5]; 
};
struct napp{
    int no;
};

void Electricpanel(double current, char xyz[], double right)
{
    printf("initializing function of amazon alexa\n");
        if (strcmp(xyz,"light")==0)
        {
            printf("dimming lights\n");
            current = current - 0.5;
            printf("optimal state reached\n");
        }
        else
        {
            if (strcmp(xyz,"fan")==0)
            {
                printf("slowing down fan\n");
                current = current - 1;
                printf("optimal state reached\n");
            }
            else
            {
                if (strcmp(xyz,"ac")==0)
                {
                    if (current <= right + 3)
                    {
                        printf("minimizing functions\n");
                        current = current - 4;
                        printf("optimal state reached\n");
                    }
                    else
                    {
                        printf("turning off ac\n");
                        current = 0;
                        printf("optimal state reached\n");
                    }
                }
                else
                {
                    if (strcmp(xyz,"mixer")==0)
                    {
                        printf("turning off mixer\n");
                        current = 0;
                        printf("optimal state reached");
                    }
                    else
                    {
                        if (strcmp(xyz,"tv")==0)
                        {
                            printf("stabilizing tv stabilizer\n");
                            current = current - 3;
                            printf("optimal state reached\n");
                        }
                        else
                        {
                            if (strcmp(xyz,"fridge")==0)
                            {
                                printf("stabilizer connected stabilizing\n");
                                current = current - 4;
                            }
                            else
                            {
                                printf("no appliances found\n");
                            }
                        }
                    }
                }
            }
        }
}

void switchbreaker(double xyz, double left, double right, char app[])
{
    printf("checking appliance %s reading\n",app);
        
        char w[100];
        strcpy(w,app);
        printf("%s\n",w);
        if (xyz >= left && xyz <= right)
        {
            printf("optimal state\n");
        }
        else
        {
            if (xyz <= (right + 8))
            {
                Electricpanel(xyz, w, right);
            }
            else
            {
                printf("switch breaker needs to to be tripped\n");
                xyz = 0;
                printf("switch tripped\n");
            }
        }
}

void neutral(double current[])
{
    double max,min,neutral;
    int i;
    max=current[0];
    min=current[0];

    for(i=0;i<=4;i++)
    { 
        if (max<current[i])
        {
            max=current[i];
        }
    
        else if (min>current[i])
        {
            min=current[i];
        }
        printf("\n");
    }

    neutral=max-min;

    if(neutral>=0&&neutral<=1)
    {
        printf("optimal state\n");
        
    }
    else 
    {
        if(neutral>=7)
        {
            printf("switch needs to trips down\n");
            current[4]=0;
            printf("triiped down switch\n");
        }
        else	
        {
            printf("electrical functions working to minimize it\n");
        }
    }
}

void checking(struct circuit a[],int ncircuit,struct napp y[],char namecircuit[][100]){
    int i,j,k;
    double left,right,xyz;
    double rfan[2], rlight[2], rac[2], rfridge[2], rtv[2], rmixer[2];
    rfan[0]=1;
    rfan[1]=2;
    rlight[0]=0.4;
    rlight[1]=0.6;
    rac[0]=20;
    rac[1]=22;
    rfridge[0]=8;
    rfridge[1]=10;
    rtv[0]=4;
    rtv[1]=5;
    rmixer[0]=4;
    rmixer[1]=5;
    printf("Checking all circuits\n");
    for (i=0;i<ncircuit;i++)
    {   
        if(strcmp(namecircuit[i],"kitchen")==0)
        {
            printf("checking circuit1: %s\n",namecircuit[i]);
            double mixer[5],fridge[5];
            for(j=0;j<y[i].no;j++)
            {
                
                if(strcmp(a[i].x[j].app,"mixer")==0)
                {
                    char app[100];
                    strcpy(app,a[i].x[j].app);
                    for ( k = 0; k <=4; k++)
                    {
                        
                        printf("enter current reading for %s:",a[i].x[j].app);
                        scanf("%lf",&mixer[k]);
                        xyz=mixer[k];
                        left=rmixer[0];
                        right=rmixer[1];
                        switchbreaker(xyz,left,right,app);
                        printf("\n");
                    }
                    neutral(mixer);
                }
                else if (strcmp(a[i].x[j].app,"fridge")==0)
                {
                    char app[100];
                    strcpy(app,a[i].x[j].app);
                    
                    for ( k = 0; k <=4; k++)
                    {
                        
                    printf("enter current reading for %s:",a[i].x[j].app);
                    scanf("%lf",&fridge[k]);
                    xyz=fridge[k];
                    left=rfridge[0];
                    right=rfridge[1];
                    switchbreaker(xyz,left,right,app);
                    printf("\n");
                    }
                    neutral(fridge); 
                }
                printf("\n");
                
            }
        }
        else if(strcmp(namecircuit[i],"hall")==0) 
        {
           double ac[5],light[5],tv[5],fan[5];
           for(j=0;j<y[i].no;j++)
           {
                if(strcmp(a[i].x[j].app,"ac")==0) 
                {
                        char app[100];
                        strcpy(app,a[i].x[j].app);
                        
                        for ( k = 0; k <=4; k++)
                        {
                            
                            printf("enter current reading for %s:",a[i].x[j].app);
                            scanf("%lf",&ac[k]);
                            xyz=ac[k];
                            left=rac[0];
                            right=rac[1];
                            switchbreaker(xyz,left,right,app);
                            printf("\n");
                        }
                        neutral(ac);
                    
                }
                
                else if(strcmp(a[i].x[j].app,"tv")==0) 
                {
                        char app[100];
                        strcpy(app,a[i].x[j].app);
                        
                        for ( k = 0; k <=4; k++)
                        {
                            
                            printf("enter current reading for %s:",a[i].x[j].app);
                            scanf("%lf",&tv[k]);
                            xyz=tv[k];
                            left=rtv[0];
                            right=rtv[1];
                            switchbreaker(xyz,left,right,app);
                            printf("\n");
                        }
                        neutral(tv);
                    
                }
                
                else if(strcmp(a[i].x[j].app,"fan")==0) 
                {
                        char app[100];
                        strcpy(app,a[i].x[j].app);
                        
                        for ( k = 0; k <=4; k++)
                        {
                            
                            printf("enter current reading for %s:",a[i].x[j].app);
                            scanf("%lf",&fan[k]);
                            xyz=fan[k];
                            left=rfan[0];
                            right=rfan[1];
                            switchbreaker(xyz,left,right,app);
                            printf("\n");
                        }
                        neutral(fan);
                    
                }
                
                else if(strcmp(a[i].x[j].app,"light")==0) 
                {
                        char app[100];
                        strcpy(app,a[i].x[j].app);
                        
                        for ( k = 0; k <=4; k++)
                        {
                            
                            printf("enter current reading for %s:",a[i].x[j].app);
                            scanf("%lf",&light[k]);
                            xyz=light[k];
                            left=rlight[0];
                            right=rlight[1];
                            switchbreaker(xyz,left,right,app);
                            printf("\n");
                        }
                        neutral(light);
                    
                }
                printf("\n");
           }
        
        }
        printf("\n");
    }
}
void virtualsimulation ()
{
  int nappliance, ncircuit, i, j, k, b;
  printf ("Enter number of circuit:");
  scanf ("%d",&ncircuit);
  struct circuit a[ncircuit];
  char namecircuit[ncircuit][100],name[30];
  struct napp y[ncircuit];
  
  printf("\n");
  for ( i = 0; i <ncircuit; i++)
   {
    printf("enter circuit name: ");
    
    scanf("%s",namecircuit[i]);
    printf("enter number of appliance in circuit %d: ",i);
    fflush(stdin);
    scanf("%d",&nappliance);
    y[i].no=nappliance;
    for(j = 0; j < nappliance; j++)
      { 
        printf("enter appliance name :");
        fflush(stdin);
        scanf("%s",name);
        strcpy(a[i].x[j].app,name);
        printf("%s",a[i].x[j].app);
        printf("\n");
      }
    }
    checking(a,ncircuit,y,namecircuit); 
    
} 
#include<stdio.h>
int lbd()
{
    struct curapp
    {
    int curfan,curlight,curac,curtv,curfridge;
    }appcur,*pappcur;
    appcur.curfan=2;
    appcur.curlight=2;
    appcur.curac=20;
    appcur.curtv=4;
    appcur.curfridge=8;
    struct noapp
    {
        int nofan, nolight, noac, notv, nofridge, status, c1neutral, c2neutral, c2high, c2low, c1high, c1low;
    }appno,*pappno;
    pappcur=&appcur;
    pappno=&appno;
    pappcur=&appcur;
    char choice[5];
    printf("Current:\nFAN-2amps\nLIGHT-1amp\nAC-20amps\nTV-4amps\nFRIDGE-8amps\n\nEnter the number of fans:");
    scanf("%d",&pappno->nofan);
    printf("Enter the number of lights:");
    scanf("%d",&pappno->nolight);
    printf("Enter the number of ac:");
    scanf("%d",&pappno->noac);
    printf("Enter the number of tv:");
    scanf("%d",&pappno->notv);
    printf("Enter the number of fridge:");
    scanf("%d",&pappno->nofridge);
    pappcur->curfan=2*pappno->nofan;
    pappcur->curlight=1*pappno->nolight;
    pappcur->curac=20*pappno->noac;
    pappcur->curtv=4*pappno->notv;
    pappcur->curfridge=8*pappno->nofridge;
    printf("circuit1:\n1.Fan\n2.AC\n3.Light\ncircuit2:\n1.Tv\n2.Fridge\n\nEnter '0' for OFF and'1' for ON\n");
    printf("Current status of fan?");      
    scanf("%d",&pappno->status);
    if (pappno->status==0)
    {
        pappno->nofan=0;
    }
    else if(pappno->status!=1)
    {
        printf("Invalid Input!!Retry");
        return 0;
        
    }
    printf("Current status of light");
    scanf("%d",&pappno->status);
    if (pappno->status==0)
    {
        pappno->nolight=0;
    }
    else if (pappno->status!=1)
    {
        printf("Invalid Input!!Retry");
        return 0;
    }
    printf("Current status of ac?");
    scanf("%d",&pappno->status);
    if (pappno->status==0)
    {
        pappno->noac=0;
    }
    else if (pappno->status!=1)
    {
        printf("Invalid Input!!Retry");
        return 0;
    }
    printf("Current status of Tv?");
    scanf("%d",&pappno->status);
    if (pappno->status==0)
    {
        pappno->notv=0;
    }
    else if (pappno->status!=1)
    {
        printf("Invalid Input!!Retry");
        return 0;
    }
    printf("Current status of Fridge?");
    scanf("%d",&pappno->status);
    if (pappno->status==0)
    {
        pappno->nofridge=0;
    }
    else if (pappno->status!=1)
    {
        printf("Invalid Input!!Retry");
        return 0;
    }
    pappcur->curfan=2*pappno->nofan;
    pappcur->curlight=1*pappno->nolight;
    pappcur->curac=20*pappno->noac;
    pappcur->curtv=4*pappno->notv;
    pappcur->curfridge=8*pappno->nofridge;
    //Circuit 1
    if (pappcur->curac==0)
    {
        if (pappcur->curfan<pappcur->curlight)
        {
            pappno->c1high=pappcur->curlight;
            pappno->c1low=pappcur->curfan;
        }
        else
        {
            pappno->c1high=pappcur->curfan;
            pappno->c1low=pappcur->curlight;
        }
    }
    else
    {
        if (pappcur->curfan==0)
        {
            if (pappcur->curlight<pappcur->curac)
            {
                pappno->c1high=pappcur->curac;
                pappno->c1low=pappcur->curlight;
            }
            else
            {
                pappno->c1high=pappcur->curlight;
                pappno->c1low=pappcur->curac;
            }
            
        }
        else
        {
            if (pappcur->curlight==0)
            {
                if (pappcur->curfan<pappcur->curac)
                {
                    pappno->c1high=pappcur->curac;
                    pappno->c1low=pappcur->curfan;
                }
                else
                {
                    pappno->c1high=pappcur->curfan;
                    pappno->c1low=pappcur->curac;
                }
                
            }
            else
            {
                if (pappcur->curac>pappcur->curfan)
                {
                    if (pappcur->curac>pappcur->curlight)
                    {
                        pappno->c1high=pappcur->curac;
                    }
                    else
                    {
                        pappno->c1high=pappcur->curlight;
                    }                    
                }
                else
                {
                    if (pappcur->curfan>pappcur->curlight)
                    {
                        pappno->c1high=pappcur->curfan;
                    }
                    else
                    {
                        pappno->c1high=pappcur->curlight;
                    }
                    
                }
                if (pappcur->curac<pappcur->curfan)
                {
                    if (pappcur->curfan<pappcur->curlight)
                    {
                        pappno->c1low=pappcur->curlight;
                    }
                    else
                    {
                        pappno->c1low=pappcur->curfan;
                    }
                    
                }
                else
                {
                    if(pappcur->curac<pappcur->curlight)
                    {
                        pappno->c1low=pappcur->curac;
                    }
                    else
                    {
                        pappno->c1low=pappcur->curlight;
                    }
            
                    
                }
     
            } 
        }
        
    }
    pappno->c1neutral=pappno->c1high-pappno->c1low;
    printf("The current returned to neutral is:%d\n",pappno->c1neutral);
    // Cirucit-2
    if (pappcur->curtv<pappcur->curfridge)
    {
        pappno->c2high=pappcur->curfridge;
        pappno->c2low=pappcur->curtv;
    }
    else
    {
        pappno->c2high=pappcur->curtv;
        pappno->c2low=pappcur->curfridge;
    }
    pappno->c2neutral=pappno->  c2high-pappno->c2low;
    printf("The current returned to neutral in circuit2 is:%damps\n\n",pappno->c2neutral);
    printf("To balance the load in circuit 1 the amount current to be supplied\nin excess  to make the current returned in neutral is 0 or the lowest possible is:%damps\n\n",pappno->c1neutral);
    printf("To balance the load in circuit 2  the amount current to be supplied\nin excess  to make the current returned in neutral is 0 or the lowest possible is:%damps",pappno->c2neutral);
    return 0;
    }
int main()
{
    int n;
    printf("**************************working of loadbalancer******************************************\n");
    printf("******************Wattage is being calcukated for electric board******************************\n");
    wc();
    printf("\n************************Current returned to the neutral is being calculated");
    n=lbd();
    printf("\n************************your house is being optimized*******************************\n");
    virtualsimulation();
    printf("\n************************Your is house is optimized have a good life stay safe*******************************\n");
    return 0;
  
}