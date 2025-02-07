// See https://aka.ms/new-console-template for more information

using System.Net;
using System.Net.Sockets;

IPAddress iPAddress = new IPAddress(0); // local 주소 ip 객체
// localhost. 포트:1234로 리스너 생성(클라이언트의 요청 받을 준비)
TcpListener listener = new TcpListener(iPAddress, 1234);
listener.Start();
Console.WriteLine("서버 시작");

// accept는 클라이언트 연결 요청을 대기
// 연결 수락되면 통신 객체 반한
TcpClient tcpClient = listener.AcceptTcpClient();
Console.WriteLine("클라이언트 연결");

// 통신 객체로부터 스트림 반환
NetworkStream stream = tcpClient.GetStream();
// stream으로 읽기 스트림 생성
StreamReader streamReader = new StreamReader(stream);
string str = streamReader.ReadLine();
Console.WriteLine("클라이언트가 보낸 메시지" + str);

StreamWriter streamWriter = new StreamWriter(stream);
streamWriter.WriteLine(str);
streamWriter.Flush();

tcpClient.Close();
listener.Stop();