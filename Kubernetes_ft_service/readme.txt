1. bash setup.sh
2. dashboard 에서 서비스 이름을 보여줌 
3. dockerfile 내에 From alphine 인지 확인시키기  vscode에서 보여주기
4. loadbalancer ip를 통해서 각 서비스에 접속 kubectl get services 에 ip + port로 각각 보여줌
5. http 포트 80에서 접속시 리다이렉트 되는지 확인
6. curl -l ip 301 뜨는지
7. ftp 파일전송 되는지 파일질라에서 접속 되는지 그리고 21번 포트인지
8. wordpress user 세명 phpmyadmin에서 보여주기
9. wordpress site 에서 댓글 하나쓰고 phpmyadmin에서 보여주기
10. mysql pod 삭제 다시 생기는지 확인 phpmyadmin에서 댓글 남았는지 확인
11. grafana 에서 모니터링 되는지 확인
12. influxDB pod 삭제 후 다시 뜨면 grafana datasource tab에 influxDB가 떠 있는지 보여주기
13. mysql 서비스를 kill 함 kubectl exec deploy/mysql — pkill mysqld 하고 다시 살아나는지 확인
