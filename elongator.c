
/*
     sample two songs (a.mp3 and b.mp3) are extended and the ouput file is named as result.mp3
    */
#include<stdio.h>
void extend(FILE *fp)
{
    FILE *fp2;
    char ch;
    int pos; 
    fp2 = fopen("D:/result.mp3", "wb+");
    fseek(fp,0,SEEK_END);					// setting pointer to end of the input file
    pos=ftell(fp);							// gives number of characters present in the input file
    fseek(fp,0,SEEK_SET);					// setting pointer to the start of the input file
    fseek(fp2,0,SEEK_END);
    while (pos--)
    {
        ch = fgetc(fp);					// copying file character by character
        fputc(ch, fp2);
    }    
        fclose(fp);							// closing .mp3
	fclose(fp2);	
}

 main()
{   
    
    FILE *fp1;
    extend(fp1=fopen("D:/a.mp3","rb"));  
    fclose(fp1);
    extend(fp1=fopen("D:/b.mp3","rb"));
    fclose(fp1);  
    return 0;
}
