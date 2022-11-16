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
>>  <a href="./intro.html" target="_blank" class="btn btn-warning active" aria-current="page">게임 소개</a>
>>  <a href="./rule.html" target="_blank" class="btn btn-warning">조작법</a>
>>  <a href="./level.html" target="_blank" class="btn btn-warning">난이도</a>
>> </div>
>> ```
>> 수정 초기에는 게임 제목 아래에 열을 지정하여 설명을 넣으려고 했지만, <br>첫 화면이 깔끔해보이지 않는 것 같아, 메뉴 버튼을 통해 설명을 볼 수 있도록 하였다.
> 4. 게임소개 추가 (intro.html 파일 추가)
>> [intro.html 파일로 이동](https://github.com/hyeon317/GameProgramming/blob/main/1116%20html%20project/intro.html)
>> 해당 파일 역시 기본으로 두는 것이 별로인 것 같아, Bulma를 사용하여 스타일을 지정해주었다.
> 5. 조작법 설명 추가 (rule.html 파일 추가)
>> [rule.html 파일로 이동](https://github.com/hyeon317/GameProgramming/blob/main/1116%20html%20project/rule.html)
>> 게임 소개와 마찬가지로 Bulma를 사용하였다.
> 6. 난이도 설명 추가 (level.html 파일 추가)
>> [level.html 파일로 이동](https://github.com/hyeon317/GameProgramming/blob/main/1116%20html%20project/level.html)
>> 게임 소개와 마찬가지로 Bulma를 사용하였다.
> 7. 색상 변경
>> ```html
>> ctx.fillStyle = "#f0ad4e";
>> ```
>> drawBall(), drawPaddle(), drawBricks(), leftBricks(), drawLives() 함수에 해당 코드가 포함되어있다.<br>색상 코드는 게임 제목으로 사용했던 Bootstarp에서 warning테마의 색상 코드를 사용했다.
>> ```js
>> ctx.fillStyle = "#A6B9A0";
>> ```

> **게임하러가기**<br>
> [ORIGINAL GAME으로 이동](https://hyeon317.github.io/original_html.github.io/)<br>
> [UPGRADE GAME으로 이동](https://hyeon317.github.io/html_project.github.io/)
<br>
> **[PPT보러가기](https://github.com/hyeon317/GameProgramming/blob/main/1116%20html%20project/%EA%B2%8C%EC%9E%84%ED%94%84%EB%A1%9C%EA%B7%B8%EB%9E%98%EB%B0%8D%20-%20HTML.pdf)**
