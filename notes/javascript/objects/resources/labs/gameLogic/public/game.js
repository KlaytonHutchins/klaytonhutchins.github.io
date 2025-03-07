/*********************************************/
/**************** Don't touch ****************/
/*********************************************/
'use strict'

let components = [];

const CANVAS_WIDTH = 900;
const CANVAS_HEIGHT = 600;

let clearBoard = function(context) {
  context.clearRect(0,0, CANVAS_WIDTH, CANVAS_HEIGHT);
};

let draw = function(obj) {
  let cvs = $('#board');
  let ctx = cvs[0].getContext('2d');
  clearBoard(ctx);
  ctx.fillStyle = obj.color;
  ctx.fillRect (obj.xPos, obj.yPos, obj.width, obj.height);
};

window.addEventListener('keydown', function(e) {
  if (!square) return;

  switch(e.code) {
    case 'ArrowUp' :
      if (!square.moveUp) return;
      square.moveUp();
      break;
    case 'ArrowLeft' :
      if (!square.moveLeft) return;
      square.moveLeft();
      break;
    case 'ArrowRight' :
      if (!square.moveRight) return;
      square.moveRight();
      break;
    case 'ArrowDown' :
      if (!square.moveDown) return;
      square.moveDown();
      break;
    default : 
      return;
  }
});
/*********************************************/
