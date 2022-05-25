#include"utilities.hpp"

/** here are the parameters of the system **/
/** notice that the period must be longer 
enough wrt the propagation delays. Otherwise, 
deadlocks will appear in the model **/

/** time unit = microseconds **/

/** ~ 10 minutes would be enough **/
int INFINIT()
{
	return 600 * 1000 *1000 ; 
}

/** synchronisation period, fixed to 1 min **/
int PERIOD()
{ 
	return 60 * 1000 * 1000; 
}

int MIN(int d1, int d2, int d3, int d4){ 
	int d12 = (d1 < d2) ? d1 : d2; 
	int d34 = (d3 < d4) ? d3 : d4;
	return (d12 < d34) ? d12 : d34; 
}

/** FollowUp delay is uniform(10,20) 
This choice enforces the reception and sending 
of the Synch msg before the reception of the 
FollowUp msg **/
int chooseFollowUpDelay()
{ 
	return  10 + (random() % 10); 
}


const char* getfield(char* line, int num)
{
    const char* tok;
    for (tok = strtok(line, ",");
            tok && *tok;
            tok = strtok(NULL, ",\n"))
    {
        if (!--num)
            return tok;
    }
    return NULL;
}

const float getfield1(char* filecsv, int ln, int cl)
{

   /* int x=1;
    int y=5;
    char* s="src1/test1.csv";*/

    FILE* stream = fopen(filecsv, "r");
     int i=0;
     char line[1000];
    while (fgets(line, 1000, stream) && i<366)
            {
       		char* tmp = strdup(line);
       		if (ln==i)
       		 return atof(getfield(tmp, cl));

       	    //printf("%s",line);
       	    free(tmp);
       		i++;}
}


float minDIST(float n1, float n2, float n3){
    if( n1<=n2 && n1<=n3 )
        {return  n1;}
    if( n2<=n1 && n2<=n3 )
        {return  n2;}
    if( n3<=n1 && n3<=n2 )
        {return  n3;}
    return 0;
}

float minDISTT(float n1, float n2){
    if( n1<=n2 )
        {return  n1;}
    if( n2<n1)
        {return  n2;}
    return 0;
}


float readWH(int item){

return getfield1("discritization_test.csv", item, 3);
}

float readWV(int item){

return getfield1("discritization_test.csv", item, 4);
}

float readWP(int item){

return getfield1("discritization_test.csv", item, 2);
}

float readDIST0(int item){

return getfield1("discritization_test.csv", item, 7);
}

float readDIST1(int item){

return getfield1("discritization_test.csv", item, 8);
}

float readDIST2(int item){

return getfield1("discritization_test.csv", item, 9);
}

float readDIST3(int item){

return getfield1("discritization_test.csv", item, 10);
}

float readDIST4(int item){

return getfield1("discritization_test.csv", item, 11);
}

float readDIST5(int item){

return getfield1("discritization_test.csv", item, 12);
}


float read(){

   srand(time(NULL)); // Initialisation de la donnée seed
   float r = (float) rand(); // rand  renvoie un nombre calculé à partir de la donnée seed
	return r;
}

float compute_wf(float rp, float wf, float wh){
return 2.58;
}

void write(float value){}

	void compute_fail(int function_param_0, float function_param_1, int ID){

		float p = (1-exp(- function_param_1 * function_param_0)) *100;


	    char sentence[1000];

	    // creating file pointer to work with files
	    FILE *fptr;

		char array0[100]="";
		sprintf(array0, "%d", ID);

		char chaine[] = "fail.txt";
		strcat(array0, chaine);
	    // opening file in writing mode
	    fptr = fopen(array0, "w");

	    // exiting program
	    if (fptr == NULL) {
	        printf("Error!");
	        exit(1);
	    }
	    printf("-----------------------------------------------\n");
                printf("Failure probability (%f )", p);
	    printf(" for device (%d) \n", ID);
	    printf("-----------------------------------------------\n");
	    //fgets(sentence, sizeof(sentence), stdin);
	    fprintf(fptr, "0 %f\n", p);
	    fprintf(fptr, "1 %f", 100-p);
	    fclose(fptr);
	}

	void compute_transientFail(int function_param_0, float function_param_1, int ID){

		float p = (1-exp(- function_param_1 * function_param_0)) *100;

		int prob = (int)p;
		//printf("%f", p);

	    char sentence[1000];

	    // creating file pointer to work with files
	    FILE *fptr;

		char array0[100]="";
		sprintf(array0, "%d", ID);

		char chaine[] = "transientfail.txt";
		strcat(array0, chaine);
	    // opening file in writing mode
	    fptr = fopen(array0, "w");

	    // exiting program
	    if (fptr == NULL) {
	        printf("Error!");
	        exit(1);
	    }
	    //printf("Enter a sentence:\n");
	    //fgets(sentence, sizeof(sentence), stdin);
	    fprintf(fptr, "0 %f\n", p);
	    fprintf(fptr, "1 %f", 100-p);
	    fclose(fptr);
	}



	void compute_repair(int function_param_0, float function_param_1, int ID){

		float p = (1-exp(- function_param_1 * function_param_0)) *100;

		int prob = (int)p;
		//printf("%f", p);

	    char sentence[1000];

	    // creating file pointer to work with files
	    FILE *fptr;
		char array0[100]="";
		sprintf(array0, "%d", ID);

		char chaine[] = "repair.txt";
		strcat(array0, chaine);
	    // opening file in writing mode
	    fptr = fopen(array0, "w");

	    // exiting program
	    if (fptr == NULL) {
	        printf("Error!");
	        exit(1);
	    }
	    //printf("Enter a sentence:\n");
	    //fgets(sentence, sizeof(sentence), stdin);
	    fprintf(fptr, "0 %fn", p);
	    fprintf(fptr, "1 %f", 100-p);
	    fclose(fptr);
	}

float readMTBF(int function_param_0){

  FILE *myfile;
  float myvariable;

  	if(function_param_0==0){       myfile=fopen("MTBF0.txt", "r"); }
  	if(function_param_0==1){       myfile=fopen("MTBF1.txt", "r"); }
  	if(function_param_0==2){       myfile=fopen("MTBF2.txt", "r"); }
  	if(function_param_0==3){       myfile=fopen("MTBF3.txt", "r"); }

      fscanf(myfile,"%f",&myvariable);
      printf("%f ",myvariable);


  fclose(myfile);

return myvariable;
}


float readMTTR ( int function_param_0){

  FILE *myfile;
  float myvariable;

  	if(function_param_0==0){       myfile=fopen("MTTR0.txt", "r"); }
  	if(function_param_0==1){       myfile=fopen("MTTR1.txt", "r"); }
  	if(function_param_0==2){       myfile=fopen("MTTR2.txt", "r"); }
  	if(function_param_0==3){       myfile=fopen("MTTR3.txt", "r"); }

      fscanf(myfile,"%f",&myvariable);
      printf("%f ",myvariable);


  fclose(myfile);

return myvariable;
}


float  readMTTF  ( int function_param_0){

  FILE *myfile;
  float myvariable;

  	if(function_param_0==0){       myfile=fopen("MTTF0.txt", "r"); }
  	if(function_param_0==1){       myfile=fopen("MTTF1.txt", "r"); }
  	if(function_param_0==2){       myfile=fopen("MTTF2.txt", "r"); }
  	if(function_param_0==3){       myfile=fopen("MTTF3.txt", "r"); }

      fscanf(myfile,"%f",&myvariable);
      printf("%f ",myvariable);


  fclose(myfile);

return myvariable;
}


int modulo(int function_param_0, int function_param_1)
{
		return function_param_0 % function_param_1;
}

int flooring(float function_param_0)
{
	return (int) floor(function_param_0);
}

int maxClocks(int function_param_1, int function_param_2)
{
	if(function_param_1 > function_param_2){ return function_param_1;} else{ return function_param_2; } 

}

int minClocks(int function_param_1, int function_param_2)
{
	if(function_param_1 < function_param_2){ return function_param_1;} else{ return function_param_2; } 
}

int ceiling(float function_param_0)
{
	return (int) ceil(function_param_0);
}

float randomize(){
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_real_distribution<> dist(1, 10);

return 	dist(gen) ;

}



