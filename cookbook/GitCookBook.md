# Git 간편하게 사용하기

## 저장소 생성하기

무엇이든 현재 경로에 대하여 레파지터리를 생성하고 싶을 때 사용한다

```console
git init
```

잘 생성되었는지 보려면...

```console
git status
```

## 저장소에 파일 추가, 삭제하기

레파지터리 생성 후 파일을 추가해야 한다. 폴더나 파일을 지정해서 하나하나 등록할 수도 있다. 귀찮을 때 . 을 이용하여 모두 추가해버릴 수도 있다. 단 무시파일을 일일히 지워줘야 하는 것은 또다른 귀찮음 이다.

```console
git add .
```

레파지터리에 이미 등록된 파일을 지워줄땐

```console
git rm <filename>
```

서브디렉터리까지 모두 지워주고 싶을 땐

```console
git rm -r <filename>
```

레파지터리 뿐 아니라 파일시스템에서 지워주고 싶을 땐

```console
git rm -r -f <filename>
```

반대로 레파지터리 내에서는 지우나 파일시스템에서 지우지 않고 남겨 두고 싶을 때

```console
git rm -r --cached <filename>
```

여러 파일을 동시에 지워주고 싶을 땐

```console
git rm <filename1> <filename2> <filename3> <...>
```

## 저장소의 상태보기

레파지터리가 잘생성되었는지 어떤파일이 추가되었는지 무시파일이 잘 적용되었는지 등등 확인해 보려면 간단히 status 옵션을 사용하면 된다.

```console
git status
```

현재 경로의 status만 보고 싶을 땐 꼭 지정을 해줘야한다

```console
git status .
```

## 무시 파일 추가하기

무시파일을 만들어주는 git 명령은 없다. 그냥 탐색기, 쉘등에서 .gitignore 라는 파일을 만들고, 무시하고 싶은 파일을 추가하면 된다.

```console
C:\svn\\project\demo\trunk>dir
 C 드라이브의 볼륨에는 이름이 없습니다.
 볼륨 일련 번호: FEB3-2C3D

 C:\svn\devguru\lab1\project\flash\trunk 디렉터리

2018-03-27  오전 10:00    <DIR>          .
2018-03-27  오전 10:00    <DIR>          ..
2018-03-27  오전 10:01                14 .gitignore
2017-11-15  오후 01:50    <DIR>          binaries
2018-03-20  오전 10:00    <DIR>          build
2017-10-31  오후 01:49    <DIR>          doc
2017-09-07  오후 04:49    <DIR>          out
2017-10-17  오전 11:39    <DIR>          sample
2017-09-05  오후 06:12    <DIR>          source
               1개 파일                  14 바이트
```

그리고 원하는 파일을 무시파일(.gitignore)에 추가하자

```console
.svn
binaries
```

만약 이미 repository에 추가된 파일이라면 미리 레파지터리 상에서 파일을 지워줘야 한다.

```console
git remove binaries
```

## 커밋하기

git 를 초기화하고 필요한 파일은 추가하고 불필요한 파일은 .gitignore에 추가하고 나면 최초커밋을 할 수 있게 된다.

```console
git commit -m 'initial commit'
```

## push 하기

원격 레파지터리에 파일을 보내려면 push를 해야 한다
origin은 원격 레파지터리에 대한 이름이고 master는 브랜치 이름이다.

```console
git push origin master
```

## pull 하기

push하려하다가 만약 원격 레파지터리 대비 로컬 레파지터리가 최신이 아니라면 push하기 전에 먼저 pull을 통해 최신 변경사항을 다운 받아야 한다.

```console
git pull origin master
```

## 파일 수정 후 커밋하기

이제 initial commit을 해봤다. 이제 작업을 하면 수정된 파일이 나올 것이다.

```console
PS C:\git\github\franktech> git status
On branch master
Your branch is up-to-date with 'origin/master'.
Changes not staged for commit:
  (use "git add <file>..." to update what will be committed)
  (use "git checkout -- <file>..." to discard changes in working directory)

        modified:   cookbook/GitCookBook.md
        modified:   iot/modules/artik/artik_partition.md
```

이 파일을 커밋하기 위해서는 staged 상태로 바꿔야 한다. 위의 메세지에서 보다시피 현재는 not staged 상태이다.\
staged 상태로 만들기 위해서는 repository에 추가하기 위히 사용했던 add 명령을 다시 사용한다

```console
git add .
```

그리고 커밋 한다

```console
git commit -m 'gitcookbook과 artik_partition 수정'
```

## diff 보기

파일 커밋하기 전에 diff 를 미리 보고 커밋 메세지를 어떤 내용을 적을까 고민도 해보고 소스코드를 정리하기도 한다
아래처럼 diff 명령에 HEAD를 주면 최신 커밋과 현재 변경사항사이의 diff 를 볼 수 있다

```console
git diff HEAD
```
