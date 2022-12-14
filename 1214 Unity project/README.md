## UNITY GAME UPGRADE

> **선택한 게임**
> -----------
> BLOCK GAME<br><br>
> ![ORIGINAL GAME](https://user-images.githubusercontent.com/101097019/207533610-eae205f3-8fbc-43e3-b89e-b473edc6c2ba.png)

> **ORIGINAL GAME에서 개선하고자 한 점**<br>
> *( 14번부터는 구현하지 못한 것 )*
> ------------
> 1. 카메라 시점 변경
> 2. 바닥 색사 변경
> 3. 플레이어 모양 변경
> 4. 게임 구역 설정
> 5. 제목 추가
> 6. START 추가
> 7. COIN 추가
> 8. 마우스 제어
> 9. 낭떠러지 사망
> 10. 점프 구현
> 11. 점수(코인 획득 수) 추가
> 12. 장애물 충돌 구현
> 13. 폰트 변경
> 14. 재시작 화면
> 15. 목숨 추가
> 16. 게임 종료 안내문
> 17. 키보드 제어 추가
> 18. 정지 버튼 추가
> 등


> **세부내용**<br>
> *UPGRADE 코드가 필요한 경우 코드 포함, 개선하고자 한 점의 순서와는 무관*<br>
> 1. 카메라의 시점 변경
>> 원본 코드는 플레이어의 뒷편에서 정면을 바라보는 형태이기에, 다가오는 적들이 잘 보이지 않는다는 단점이 있었다.
>> 따라서 윗편에서 바라보는 시점으로 카메라의 위치를 변경하여 다가오는 것들이 잘 보일 수 있도록 하였다.
> 2. 바닥 색상 변경
>> 플레이어와 바닥 색상이 화이트 컬러로 동일해 잘 보이지 않는 것 같아, 바닥의 색상을 변경하였다.
> 3. 플레이어 모양 변경
>> cube모양이었던 플레이어를 게임 이름에 맞게 원형로 변경해주었다.
> 4. 게임 구역 설정
>> ```cs
>> [SerializeField]
>> private	GameObject[]	areaPrefabs;				// 구역 프리팹 배열
>> [SerializeField]
>> private	int				spawnAreaCountAtStart = 3;	// 게임 시작 시 최초 생성되는 구역 개수
>> ```
>> ``` cs
>> private void Update()
>> {
>>   if ( playerTransform.position.z - transform.position.z >= destroyDistance )
>>   {
>>	    // 새로운 구역을 생성
>>		  areaSpawner.SpawnArea();
>>		  // 현재 구역은 삭제
>>		  Destroy(gameObject);
>>    }
>> }
>> ```
>> 게임 시작 시 최초 생성되는 구역의 수는 3개로, 배열을 이용하여 구역 프리팹을 랜덤으로 3개 불러온다.
>> 플레이어가 지나가서 해당 구역이 더이상 보이지 않는다면 현재 구역을 삭제하고, 새로운 구역을 생성한다.
> 5. 제목 추가
>> ```cs
>> private void Awake()
>> {
>>   IsGameStart = false;
>> 
>>   textTitle.enabled = true;
>>   textTapToPlay.enabled = true;
>>   textCoinCount.enabled = false;
>> }
>> ```
>> 게임의 제목인 COIN BALL RUN과 학번을 추가하였다. 게임이 시작되면 사라진다.
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
>> ```
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
>> ```
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
