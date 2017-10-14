var http = require('http');

http.createServer(function (request, response){
	//发送Http头部
	//HTTP状态值：200：OK
	//内容类型：text/plain
	response.writeHead(200, {'Content-Type': 'text/plain'});
	
	//发送响应数据"Hello"
	response.end('Hello YueXia！ ^o^---fly\n');
	
}).listen(8888);

// 终端打印如下信息
console.log('Server running at http://www.dafeige.org:8888/');
