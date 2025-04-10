#include "spimcore.h"


/* ALU */
/* 10 Points */
/* Aidan*/
void ALU(unsigned A,unsigned B,char ALUControl,unsigned *ALUresult,char *Zero)
{
  // We need 7 cases (Add, Subtract, Set less than (signed and unsigned), And, Or, Shift left, A')
  // Also need a case for undefined behavior (implement last)
  switch(ALUControl){
    case 0: // Add
      *ALUresult = A + B;
      break;
    case 1: // Subtract
      *ALUresult = A - B;
      break;
    case 2: // First Set less than (signed)
      if((int)A < (int)B){
        *ALUresult = 1;
      } else {
        *ALUresult = 0;
      }
      break;
    case 3: // Second Set less than (unsigned)
      if(A < B){
        *ALUresult = 1;
      } else {
        *ALUresult = 0;
      }
      break;
    case 4: // And (unsure if its 1 & or 2)
      *ALUresult = A && B;
      break;
    case 5: // Or (unsure if its 1 | or 2)
      *ALUresult = A || B;
      break;
    case 6: // Shift left (16 bits)
      *ALUresult = B << 16;
      break;
    case 7: // A' (A negate)
      *ALUresult = !A;
      break;
    default: // For undefined behavior
      *ALUresult = 0;
      break;
  }

  // Now that the cases are defined all thats left is setting a flag (indicate if result is 0)
  if(*ALUresult == 0){
    *Zero = 1;
  } else{
    *Zero = 0;
  }
}

/* instruction fetch */
/* 10 Points */
/* Aidan*/
int instruction_fetch(unsigned PC,unsigned *Mem,unsigned *instruction)
{
  if (PC % 4 == 0){ //Check for word alignment
    *instruction = Mem[PC >> 2];
    
    return 0; //no halt
  }
    
  else{
    return 1; //halt
  }
    
  // PC >> 2; Gets array index
  // Mem already populated, PC will be initialized to address (0x4000)
  // Check for word alignment
}


/* instruction partition */
/* 10 Points */
//Max
void instruction_partition(unsigned instruction, unsigned *op, unsigned *r1,unsigned *r2, unsigned *r3, unsigned *funct, unsigned *offset, unsigned *jsec)
{
 *op = (instruction & 0xFC000000) >> 26;
 *r1 = (instruction & 0x03E000000) >> 21;
 *r2 = (instruction & 0x001F0000) >> 16;
 *r3 = (instruction & 0x0000F800) >> 11;
 *funct =  (instruction & 0x0000003F);
 *offset = (instruction & 0x0000FFFF);
 *jsec = (instruction & 0x03FFFFFF);
  
/* essentially what this code does is break down the big "instruction" 32 bit number its given into series of smaller bit numbers 
(hence the instruction_"partition") and assign them to each variable that way the CPU can run the program (what operation, registers, etc) */
}



/* instruction decode */
/* 15 Points */
//Isaac
int instruction_decode(unsigned op,struct_controls *controls)
{
  //This needs to effect multiple things based on this struct
  /*typedef struct
  {
  char RegDst;
  char Jump;
  char Branch;
  char MemRead;
  char MemtoReg;
  char ALUOp;
  char MemWrite;
  char ALUSrc;
  char RegWrite;
  }struct_controls;
  The struct_controls *controls lets us use it like controls->RegDst = value
  */
  //This will have to be a case by case, so advising either and If/then or switch statements
  //it has to be something similar to 
  /*if(op == <value>){
      controls->RegDst = <value>;
      controls->Jump = <value>;
      controls->Branch = <value>;
      controls->MemRead = <value>;
      controls->MemtoReg = <value>;
      controls->ALUOp = <value>;
      controls->MemWrite = <value>;
      controls->ALUSrc = <value>;
      controls->RegWrite = <value>;
    } if(etc)
  

}

/* Read Register */
/* 5 Points */
//Isaac
void read_register(unsigned r1,unsigned r2,unsigned *Reg,unsigned *data1,unsigned *data2)
{
  //According to spimcore.c Reg works as the array of registers :)
  *data1 = Reg[r1];
  *data2 = Reg[r2];
  
  //return *data1, *data2  --- I don't believe you need to return a void to update values in void func
}


/* Sign Extend */
/* 10 Points */
//Isaac
void sign_extend(unsigned offset,unsigned *extended_value) //Extending from 16 bits to 32
{
  /*If postive{Extend with zeros}*/
  /*If negative{Extend with ones}*/
  testValue = (offset>>15); //Check most significant bit
  switch(testValue){
    case 1:
      *extended_value = offset | 0xFFFF0000; //Negative so extend with 1's
      break;
    case 0:
      *extended_value = offset & 0x0000FFFF; //Positive so extend with zeros
      break;
  }
  

}

/* ALU operations */
/* 10 Points */
int ALU_operations(unsigned data1,unsigned data2,unsigned extended_value,unsigned funct,char ALUOp,char ALUSrc,unsigned *ALUresult,char *Zero)
{

}

/* Read / Write Memory */
/* 10 Points */
//Dillon
int rw_memory(unsigned ALUresult,unsigned data2,char MemWrite,char MemRead,unsigned *memdata,unsigned *Mem)
{
  if (ALUresult % 4 == 0){ 
    if (memRead == 1){ 
      *memdata = Mem[ALUresult >> 2]; //read mem location addresed by ALUresult to memdata 
      
      return 0; //no halt
    }
      
    if (memWrite == 1){
      Mem[ALUresult >> 2] = data2; //write data2 to mem location addressed by ALUresult
      
      return 0; //no halt
    }
  }
    
  else {
    return 1; //halt
  }
}


/* Write Register */
/* 10 Points */
//Dillon
void write_register(unsigned r2,unsigned r3,unsigned memdata,unsigned ALUresult,char RegWrite,char RegDst,char MemtoReg,unsigned *Reg)
{

}

/* PC update */
/* 10 Points */
void PC_update(unsigned jsec,unsigned extended_value,char Branch,char Jump,char Zero,unsigned *PC)
{

}

