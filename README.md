lime
====

유용한 php extension 만들기


설치 방법
--------
```
[root@ test]# cd php-x.x.x/ext
[root@ test]# ./ext_skel --extname=lime
[root@ test]# cd lime
[root@ test]# git clone git@github.com:yejune/lime.git foo; mv foo/* .; rm -rf foo;
[root@ test]# phpize
[root@ test]# ./configure
[root@ test]# make; make install
```


