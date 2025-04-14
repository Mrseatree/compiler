program TestCASE
	var a,b,c:integer;{a,b,c 分别表示在买笔方案中，6 元、5 元和 4 元钱笔的数目} 
 		x,y:integer;{x，y 分别表示剩余班费和买完最多的 4 元笔后剩的钱} 
 begin 
 	write('x=');readln(x); {输入 x} 
 	c:=x div 4; {4 元笔最多买的数目} 
    y:=x mod 4; {求买完 c 支 4 元笔后剩余的钱数 y} 
 	case y of 
 		0 : begin a:=0;b:=0; end; 
 		1 : begin a:=0;b:=1;c:=c-1; end; 
 		2 : begin a:=1;b:=0; c:=c-1;end; 
 		3 : begin a:=1;b:=1; c:=c-2;end; 
 	end; 
 	writeln('a=',a,'b=',b,'c=',c); 
end.