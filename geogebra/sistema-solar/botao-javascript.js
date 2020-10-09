/*
var todos_pontos = ggbApplet.getAllObjectNames("Point");
var todos_angulos_planetas = ["anguloTerra"];

for(var i of todos_pontos){
  for(var j of todos_angulos_planetas){
    if(todos_pontos[i] == todos_angulos_planetas[j]){
 //     var xml = ggbApplet.getXML(todos_angulos_planetas[j]) + "";      
 //     var ggbCode = "if(" + todos_pontos[i] + " == 360){ " + todos_angulos_planetas[j] + " = 0 } ";
 //     code = "<javascript val='" + ggbCode + "' /> </element>";
//      xml = xml.replace("/<\/element>/", code);
     xml = xml.replace("/<\/element/", "<\/element>");
       ggbApplet.evalXML(xml);
      
    }
  }
}

forEac
*/

var todos_angulos_planetas = ["anguloTerra"];

for(const angulo_planeta of todos_angulos_planetas){
  var angulo_planeta_array = document.querySelectorAll('[label="' + angulo_planeta + '"]');
  var js = document.creatElement("javascript");
  var ggbscript = document.createElement("ggbscript");
  var ggbcode = document.createTextNode( "if(" + angulo_planeta + " == 360){ " + angulo_planeta + " = 0 }" );
  ggbscript.appendChild(ggbcode);
  js.appendChild(ggbscript);
  angulo_planeta_array[0].appendChild(js);
  
  
  
}

ggbApplet.evalCommand("B = (1,0)");
// var js = document.createElement("javascript");
// js.setAttribute("val", "alert();" );
// ggbApplet.evalXML(js);

var b_point = ggbApplet.getXML("B");
// b_point.getElementsByTagName("javascript");
var row_b = b_point.split("\n");
var qtde_linhas = row_b.length;
var found = false;
for(var i=0; i < qtde_linhas; i++){
  if (row_b.includes("<javascript"){
    found = true;
    row_b.splice(i, 1);
    break;
  }
}
var newcode = "<javascript val=''>";
row_b.push(newcode);
ggbApplet.evalXML(row_b.join('\n'));
