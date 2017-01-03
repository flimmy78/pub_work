
ALL=test select_sort bubble_sort insert_sort
APP:$(ALL)

test:
	$(CC) -g -Wall 00-test.c -o test

select_sort:
	$(CC) -g -Wall 01-select_sort.c -o select_sort

bubble_sort:
	$(CC) -g -Wall 02-bubble_sort.c -o bubble_sort

insert_sort:
	$(CC) -g -Wall 03-insert_sort.c -o insert_sort

clean:
	$(RM) a.out $(ALL)
