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

