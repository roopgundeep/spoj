test = input();
for i in range(test):
	a = raw_input().split();
	best = 0;
	prev = 0;
	wordcount=0;
	for i in range(len(a)):
		length = len(a[i]);
		if (length==prev):
			wordcount=wordcount+1;
		else:
			if (wordcount > best):
				best=wordcount;
			prev=length;
			wordcount=1;
	if (wordcount>best):
		print wordcount;
	else:
		print best;
