%---------------------------------------------------
% Dijkstra Algorithm 
% Modified version of Dimas Aryo's script (mr.dimasaryo@gmail.com)
%
% usage
% [route] = dijkstra(Graph, source, destination)
%
%---------------------------------------------------
function [L] = dijkstra(A,s,d)

if s==d
    L=[s];
else

%setupgraph
GG=A;
bb=inf;
ss=1;

if ss==1
    for i=1 : size(GG,1)
        for j=1 :size(GG,1)
            if GG(i,j)==0
                GG(i,j)=bb;
            end
        end
    end
end
if ss==2
    for i=1 : size(GG,1)
        for j=1 : size(GG,1)
            if GG(i,j)==bb
                GG(i,j)=0;
            end
        end
    end
end
A=GG;
%setupgraphEnd

if d==1
    d=s;
end

%exchangenode
JJ=A;
xx=1;
yy=s;
%Exchange element at column xx with element at column yy;
buffer=JJ(:,xx);
JJ(:,xx)=JJ(:,yy);
JJ(:,yy)=buffer;

%Exchange element at row xx with element at row yy;
buffer=JJ(xx,:);
JJ(xx,:)=JJ(yy,:);
JJ(yy,:)=buffer;
A=JJ;
%exchangenodeEnd

lengthA=size(A,1);
W=zeros(lengthA);
for i=2 : lengthA
    W(1,i)=i;
    W(2,i)=A(1,i);
end

for i=1 : lengthA
    D(i,1)=A(1,i);
    D(i,2)=i;
end

D2=D(2:length(D),:);
L=2;
while L<=(size(W,1)-1)
    L=L+1;
    D2=sortrows(D2,1);
    k=D2(1,2);
    W(L,1)=k;
    D2(1,:)=[];
    for i=1 : size(D2,1)
        if D(D2(i,2),1)>(D(k,1)+A(k,D2(i,2)))
            D(D2(i,2),1) = D(k,1)+A(k,D2(i,2));
            D2(i,1) = D(D2(i,2),1);
        end
    end
    
    for i=2 : length(A)
        W(L,i)=D(i,1);
    end
end
if d==s
    L=[1];
else
    L=[d];
end

%listdjikstra
LL=L;
WW=W;
ss=s;
dd=d;
index=size(WW,1);
while index>0
    if WW(2,dd)==WW(size(WW,1),dd)
        LL=[LL ss];
        index=0;
    else
        index2=size(WW,1);
        while index2>0
            if WW(index2,dd)<WW(index2-1,dd)
                LL=[LL WW(index2,1)];
                LL=listdijkstra(LL,WW,ss,WW(index2,1));
                index2=0;
            else
                index2=index2-1;
            end
            index=0;
        end
    end
end
L=LL;
%listdjikstraEnd
L=fliplr(L); %Path is in reverse
end
% 
% Copyright (c) 2012, Dimas Aryo
% All rights reserved.
% 
% Redistribution and use in source and binary forms, with or without
% modification, are permitted provided that the following conditions are
% met:
% 
%     * Redistributions of source code must retain the above copyright
%       notice, this list of conditions and the following disclaimer.
%     * Redistributions in binary form must reproduce the above copyright
%       notice, this list of conditions and the following disclaimer in
%       the documentation and/or other materials provided with the distribution
%     * Neither the name of the Yogyakarta State University nor the names
%       of its contributors may be used to endorse or promote products derived
%       from this software without specific prior written permission.
% 
% THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
% AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
% IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
% ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE
% LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
% CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
% SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
% INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
% CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
% ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
% POSSIBILITY OF SUCH DAMAGE.