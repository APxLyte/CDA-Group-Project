#include "spimcore.h"


/* ALU */
/* 10 Points */
/* Aidan*/
void ALU(unsigned A,unsigned B,char ALUControl,unsigned *ALUresult,char *Zero)
{

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
void instruction_partition(unsigned instruction, unsigned *op, unsigned *r1,unsigned *r2, unsigned *r3, unsigned *funct, unsigned *offset, unsigned *jsec)
{

}



/* instruction decode */
/* 15 Points */
//Isaac
int instruction_decode(unsigned op,struct_controls *controls)
{

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
      
    else if (memWrite == 1){
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

