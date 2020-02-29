Read Text Files

void main()
{
 char pcMyLines[10000];

 ReadLines("C:\\MyTestFile.txt", 10, 5, pcMyLines, 12345);
}

// This function reads n lines from a file
// Returns the amount of bytes read
int ReadLines(const char *pcFile, const int iStartLine, const int iTotLines, char *pcBuffer, const int iBufLen)
{
 FILE *fSrc;
 int   iLines = 0, j, iPos, iByteCount = 0;

 // Try to open the file
 if(fSrc = fopen(pcFile, "r"))
 {
   // Try to locate the starting line
   if(iPos = GetLinePos(fSrc, iStartLine))
   {
     // Set the starting position
     if(!fseek(fSrc, iPos, SEEK_SET))
     {
       // Read the lines
       for(iLines=0;iLines<iTotLines;iLines++)
       {
         // Read the line
         if((j = ReadLine(fSrc, iPos, pcBuffer, iBufLen - iByteCount)) == -1) break;
         iByteCount += j;
       }
     }
   }

   // Close the file
   fclose(fSrc);
 }

 // Return the amount of bytes in the buffer, or -1 for failure
 return iLines == iTotLines ? iByteCount : -1;
}


// This function reads a single line from a file
int ReadLine(FILE *fSrc, const int iStartPos, char *pcBuffer, const int iBufLen)
{
 int iCount = 0;

 // Set the starting position
 if(!fseek(fSrc, iStartPos, SEEK_SET))
 {
   // Keep reading characters while we can
   while(!feof(fSrc) && (iCount < iBufLen))
   {
     // Read the character
     pcBuffer[iCount] = (char)fgetc(fSrc);
     if(pcBuffer[iCount++] == '\n') break;
   }
 }
 else iCount = -1;

 return iCount;
}

// This function locates a line in a file
// Returns the position of the line in the file
int GetLinePos(FILE *fSrc, const int iLine, const int iStartPos /* 0 */)
{
 char  pcBuffer[4096];
 int   i, iPos = 0, iLines = 0, iBytes;

 // Set the start position
 if(!fseek(fSrc, iStartPos, SEEK_SET))
 {
   // Read the (next) block of data
   while(iBytes = fread(pcBuffer, sizeof(char), 4096, fSrc))
   {
     // Go through the block
     for(i=0;i<iBytes;i++)
     {
       // Do we have a new line?
       if(pcBuffer[i] == '\n')
       {
         // Update the line count
         iLines++;

         // Have we reached the desired line?
         if(iLines == iLine)
         {
           // Store the position
           iPos += i;
           break;
         }
       }
     }

     // Update the position
     iPos += iBytes;
   }
 }

 // Return the position of the line in the file, or -1 for failure
 return iLines == iLine ? iPos : -1;
}
