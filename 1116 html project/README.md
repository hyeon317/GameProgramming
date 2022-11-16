## HTML GAME UPGRADE

> **선택한 게임**
> -----------
> BLOCK GAME<br><br>
> ![ORIGINAL GAME](https://user-images.githubusercontent.com/101097019/202085982-7365a0c5-baf9-4e43-af81-bbe0ebf14b60.png)

> **ORIGINAL GAME에서 개선하고자 한 점**<br>
> *( 9번부터는 구현하지 못한 것 )*
> ------------
> 1. 타이틀 변경
> 2. 게임 제목 추가
> 3. 설명 추가
> 4. 난이도 버튼 추가
> 5. 색상 변경
> 6. 게임이 끝났을 때 확인창
> 7. 공 움직임의 오류 수정
> 8. 패들 움직임의 오류 수정
> 9. 마우스 제어 삭제
> 10. 플레이 시간 추가
> 11. 목숨이 줄었을 때 소리
> 12. 게임 중지르 위한 버튼
> 13. 다른 게임으로 넘어가는 페이지 추가
> 등


> **세부내용**<br>
> *UPGRADE 코드 포함, 개선하고자 한 점의 순서와는 무관*<br>
> 1. 타이틀 변경
>>```html
>><title>BLOCK GAME</title>
>>```
>> 타이틀에서부터 어떤 게임인지 알 수 있는 것이 좋을 것 같아, 이름을 적게 되었다.
> 2. 게임 제목 추가
>>```html
>><div class = "container-fluic p-5 bg-warning text-white text-center">
>>  <h1>BLOCK GAME</h1>
>>  <p>소프트웨어학과 2020875042 이수현</p>
>></div>
>>```
>> 게임의 제목과 부제목을 표시할 수 있도록 만들었다. <br>아무런 설정 없이 기본으로 두는 것은 별로인 것 같아, <br>Bootstrap을 사용하여 스타일을 지정해주었다.
> 3. 메뉴 버튼 추가
>> ```html
>> <div class="btn-group" style="display:flec; justify-content: center;" >
>>   <a href="./intro.html" target="_blank" class="btn btn-warning active" aria-current="page">게임 소개</a>
>>   <a href="./rule.html" target="_blank" class="btn btn-warning">조작법</a>
>>   <a href="./level.html" target="_blank" class="btn btn-warning">난이도</a>
>> </div>
>> ```
>> 수정 초기에는 게임 제목 아래에 열을 지정하여 설명을 넣으려고 했지만, <br>첫 화면이 깔끔해보이지 않는 것 같아, 메뉴 버튼을 통해 설명을 볼 수 있도록 하였다.
> 4. 게임소개 추가 (intro.html 파일 추가)
>> [intro.html 파일로 이동](https://github.com/hyeon317/GameProgramming/blob/main/1116%20html%20project/intro.html)<br>
>> 해당 파일 역시 기본으로 두는 것이 별로인 것 같아, Bulma를 사용하여 스타일을 지정해주었다.
> 5. 조작법 설명 추가 (rule.html 파일 추가)
>> [rule.html 파일로 이동](https://github.com/hyeon317/GameProgramming/blob/main/1116%20html%20project/rule.html)<br>
>> 게임 소개와 마찬가지로 Bulma를 사용하였다.
> 6. 난이도 설명 추가 (level.html 파일 추가)
>> [level.html 파일로 이동](https://github.com/hyeon317/GameProgramming/blob/main/1116%20html%20project/level.html)<br>
>> 게임 소개와 마찬가지로 Bulma를 사용하였다.
> 7. 색상 변경
>> ```js
>> ctx.fillStyle = "#f0ad4e";
>> ```
>> drawBall(), drawPaddle(), drawBricks(), leftBricks(), drawLives() 함수에 해당 코드가 포함되어있다.<br>색상 코드는 게임 제목으로 사용했던 Bootstarp에서 warning테마의 색상 코드를 사용했다. 해당 색상은 highlevel에 적용되었다.
>> ```js
>> ctx.fillStyle = "#A6B9A0";
>> ```
>> 난이도에 따라 다른 색상을 적용하고 싶어, lowlevel에는 다른 색상을 적용하였다.
> 8. 난이도 버튼 추가
>>```html
>> <div class="d-grid gap-2 col-6 mx-auto">
>>     <button type="button" class="btn btn-outline-warning" onclick = "lowlevel()">난이도 하</button>
>>     <button type="button" class="btn btn-outline-warning" onclick = "highlevel()">난이도 상</button>
>> </div>
>> ```
>> 난이도를 어떻게 선택할 지 생각해 보다가 버튼을 통해 난이도를 지정해야겠다고 생각했다. 버튼 역시 Bootstrap을 사용하였다.
> 9. 남은 블럭 수 추가
>> ```js
>> let block = 15;
>> function leftBlock() {
>>    ctx.font = "16px Arial";
>>    ctx.fillStyle = "A6B9A0";
>>    ctx.fillText("Left Blocks: "+parseInt(block-score), 200, 20);
>> }
>> ```
>> 코드의 윗부분에 총 블럭 수를 담은 변수를 선언한다. <br>leftBlock()함수를 만들어 남은 블럭 수를 표시할 수 있게 한다.
> 10. 패들이 벽에 들어가는 현상 수정
>> ```js
>> if(rightPressed && paddleX < canvas.width-paddleWidth) {
>>    paddleX += 7;
>> }
>> else if(leftPressed && paddleX > 0) {
>>    paddleX -= 7;
>> }
>> ```
>> 키를 너무 오래 누르고 있으면 패들이 캔버스 영역을 넘어가기 때문에 캔버스 안에서만 움직일 수 있도록 변경하였다.
> 11. 공이 벽에 들어가는 현상 수정
>> ```js
>> if(x + dx > canvas.width-ballRadius || x + dx < ballRadius) {
>>    dx = -dx;
>> }
>> if(y + dy < ballRadius) {
>>    dy = -dy;
>> }
>> else if(y + dy > canvas.height-ballRadius) {
>>    if(x > paddleX && x < paddleX + paddleWidth) {
>>    ....
>> ```
>> 공이 벽에 닿이는 순간 튕겨나올 수 있어야 하는데, 원본 코드에서는 공이 벽 안쪽으로 약간 들어갔다가 나오는 현상이 발견되었다.<br>기준을 공의 원점에 두고 계산해서 생긴 문제점으로, 원의 둘레에 두고 계산하기 위해 원점과 벽 사이의 거리가<br>공의 반지름과 같아졌을 때, 공이 튕겨나올 수 있도록 변경하였다.
> 12. 마우스 제어 부분 제거
>> ```js
>> //document.addEventListner("mousemove", moseMoveHandler, false);
>> //function mouseMoveHandler(e) {
>> //   let relativeX = e.clientX - canvas.offsetLeft;
>> //   if(relativeX > 0 && relativeX < canvas.width) {
>> //     paddleX = relativeX - paddleWidth/2;
>> //   }
>> // }
>> 키보드와 마우스로 모두 게임을 실행해보니 함께 작용하는 것이 불편하다고 생각되었다. <br>따라서 마우스로 게임을 제어하던 부분을 주석처리하여, 게임은 키보드로만 진행될 수 있게 하였다.
> 13. 게임 마무리 시 안내문 출력
>> ```js
>> let conf = confirm("축하합니다 게임에서 이겼습니다. 다시 하시겠습니까?");
>>    if(conf == true) {
>>      document.location.reload();
>>    } else if(conf == false) {
>>      window.close();
>>      }
>>    }
>> ```
>> 원래는 alert로 게임의 결과만 알려주고 바로 reload시켰는데, 다시 할지 물어보는 것이 필요하다고 생각되었다.<br>따라서 confirm을 이용해 질문에 값이 true이면 reload, false이면 화면을 종료한다.
> 14. FOOTER 추가
>> ```html
>> <footer class = "bg-light text-center text-lg-start">
>>    <nav>
>>      <a href='https://naver.com' target='_blank'>Blog</a>
>>      <a href='https://github.com/hyeon317/GameProgramming/tree/main/1116%20html%20project' target='_blank'>Github</a>
>>    </nav>
>>    <p>
>>      <span>제작자 : 이수현(2020875042)</span><br/>
>>      <span>이메일 : tn_gus0317@naver.com</span><br/>
>>      <span>Copyright 2022. cocoder. All Rights Reserved.</span>
>>    </p>
>> </footer>
>> 게임 제작자의 정보를 담기 위해 footer태그를 이용했다.<br>blog는 주소가 따로 없어 naver를 넣었고, github는 해당 파일의 git주소를 넣었다.<br>추가로 제작자의 이름과 학번, 이메일을 넣었다.
> 15. framework 사용
>> (1) Bootstrap
>> ```html
>> <link href="https://cdn.jsdelivr.net/npm/bootstrap@5.2.2/dist/css/bootstrap.min.css" rel="stylesheet">
>> <script src="https://cdn.jsdelivr.net/npm/bootstrap@5.2.2/dist/js/bootstrap.bundle.min.js"></script>
>> ```
>> (2) Bulma
>> ```html
>> <link rel="stylesheet" href="https://cdn.jsdelivr.net/npm/bulma@0.9.4/css/bulma.min.css">
>> ```
>> 스타일을 지정하기 위해 framework를 사용하였다.

> **게임하러가기**<br>
> [ORIGINAL GAME으로 이동](https://hyeon317.github.io/original_html.github.io/)<br>
> [UPGRADE GAME으로 이동](https://hyeon317.github.io/html_project.github.io/)

> **[PPT보러가기](https://github.com/hyeon317/GameProgramming/blob/main/1116%20html%20project/%EA%B2%8C%EC%9E%84%ED%94%84%EB%A1%9C%EA%B7%B8%EB%9E%98%EB%B0%8D%20-%20HTML.pdf)**
