a=input();
i=0;
while (i<a):
	b=raw_input();
	p=len(b);
#	print 'i==',i;
	i=i+1;
	if(p==0):
		print 0;
		continue;
	s=b.split();
	prev=len(s[0]);
#	print prev
	count=0;
	maximum=1;
	for k in s:
#	print k;
		length=len(k);
#		print k,length,prev,count,maximum;
		if(prev==length):
			count = count +1;
			if(maximum<=count):
				maximum=count;
		else:
			if(maximum<=count):
				maximum=count;
			count=1;
			prev=length;
	print maximum;

