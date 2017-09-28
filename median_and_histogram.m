a=imread('1.pnm');
figure,imshow(c);
b= medfilt2(c);
imshowpair(c,b,'montage')
histogram(a)
d=imread('negative.pnm');
histogram(d)
