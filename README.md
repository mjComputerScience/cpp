C++ 스터디 과제제출용 레퍼지토리입니다.

자신의 이름으로 branch를 만들고 과제를 제출하세요.

웹으로만 사용하시려면 아래 내용은 필요없지만
배워놓으면 다 쓸데가 있습니다.

--- 초기 셋팅 ---
git init
git remote add origin https://github.com/mjComputerScience/cpp.git
git pull origin yourBranch
    // 위 커맨드를 치기 전에 웹에서 자신의 이름으로 branch를 만들어놓아야 합니다.
git branch yourBranch
git checkout yourBranch
git push --set-upstream origin yourBranch

--- 파일 추가, 수정하고 ---
git add .
git commit -m "message"
git push


--- git과 github가 무엇인가 ---
https://namu.wiki/w/Git
https://namu.wiki/w/GitHub?from=github

github 사용법 배우기. 콘솔 명령어로 배우는게 좋습니다.
https://backlogtool.com/git-guide/kr/
