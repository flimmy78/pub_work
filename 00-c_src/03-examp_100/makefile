
CFLAGS= -g -Wall

APP:=test_0 test cos_01 cos circle score submultiple lastdigits MulTable ZeroTotal\


ALL:$(APP)

#01
test_0:
	$(CC) $(CFLAGS) 00-test_0.c -o test_0

#02
test:
	$(CC) $(CFLAGS) 00-test.c -o test

#03
cos_01:
	$(CC) $(CFLAGS) 01-cos_01.c -o cos_01 -lm

#04
cos:
	$(CC) $(CFLAGS) 01-cos.c -o cos -lm

#05
circle:
	$(CC) $(CFLAGS) 02-circle.c -o circle -lm

#06
score:
	$(CC) $(CFLAGS) 03-score.c -o score

#07
submultiple:
	$(CC) $(CFLAGS) 04-submultiple.c -o submultiple

#08
lastdigits:
	$(CC) $(CFLAGS) 05-lastdigits.c -o lastdigits

#09
MulTable:
	$(CC) $(CFLAGS) 06-MulTable.c -o MulTable

#10
ZeroTotal:
	$(CC) $(CFLAGS) 07-ZeroTotal.c -o ZeroTotal

clean:
	$(RM) a.out $(APP)

