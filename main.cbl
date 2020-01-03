       IDENTIFICATION DIVISION.
       PROGRAM-ID. BRAINFUCOIDAN.
       ENVIRONMENT DIVISION.
       INPUT-OUTPUT SECTION.
       FILE-CONTROL.
       SELECT F1 ASSIGN TO "../sourcecodes/hello.bf".
       DATA DIVISION.
       FILE SECTION.
       FD F1.
       01 AC   PIC 9(5).
       01 F1R.
           03 FSRC PIC X(300000000).
       WORKING-STORAGE SECTION.
       01 SRCDATA.
           03 SRC  PIC X(300000000).
       01 MEM.
           03 MEME PIC 9(1) OCCURS 30000.
       01 POS  PIC 9(5).
       01 I    PIC 9(10).
       01 CNT  PIC 9(3).
       PROCEDURE DIVISION.
       OPEN INPUT F1.
       READ F1 INTO SRCDATA.
       CLOSE F1.
       STOP RUN.

       