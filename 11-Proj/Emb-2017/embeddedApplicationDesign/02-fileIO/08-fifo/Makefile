.PHONY:all clean
OBJ_PRODUCER=producer
OBJ_CUSTOMER=customer
CFLAGS= -g -Wall

all:producer customer

producer:
	$(CC) -o $(OBJ_PRODUCER) producer.c lock_set.c $(CFLAGS)

customer:
	$(CC) -o $(OBJ_CUSTOMER) customer.c lock_set.c $(CFLAGS)

clean:
	$(RM) $(OBJ_PRODUCER)	$(OBJ_CUSTOMER) a.out .*.*.swp myfifo
