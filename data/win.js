 var js;
       function send_request( server) {
        
        request = new XMLHttpRequest();
        request.open("GET", server, true);
        request.send();

    }
$.getJSON('http://192.168.1.76/cir.json', function (data) {
 js = data;
 
});




function send(name){

            
                for (var i = 0; i < js.main.length; i++) {
                  if (name == js.main[i].name) {
                    send_request('http://192.168.1.76/ir?code=' + js.main[i].code);
                  }
                }
                
               
       
    }

    function setZoom() {
        var v = $("#zoom").val();
       $("#main-box").css("zoom", v + '%');
        $("#main-box").css("-webkit-transform", "rotate(-0deg)");
        
    }
    
    $(document).ready(function() {
     var v = 80;
        $("#main-box").css("zoom", v + '%');
        $("#main-box").css("-webkit-transform", "rotate(-0deg)");
        
        $("#zoom").val(v);


        $('#in').load('http://192.168.1.76/main.json',function(){$('.button-container').on('click',function(on){
  console.log(on.currentTarget.id);
    send(on.currentTarget.id);
  console.log('on.currentTarget.id');
});});
        $('.ui-input-text').attr('id', 'vid');
        $("#zoom").change(function() {
            setZoom();
            
        });
    })

