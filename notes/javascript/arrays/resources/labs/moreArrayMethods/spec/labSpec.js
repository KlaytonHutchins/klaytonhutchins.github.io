describe(`Array Methods Test Suite`, function(){
  describe(`1 : Modify ex1 ...`, function(){
    it(`returns an array`, function(){
      expect(Array.isArray(ex1([1,2,3,4,NaN]))).to.be.true;
    });
    it(`removes NaN`, function(){
      expect(ex1([1,2,3,4,NaN]).length).to.equal(4);
      expect(ex1([1,2,3,4,NaN])).not.to.include.members([NaN]);
    });
    it(`did not alter the original array`, function(){
      expect(startingArray.length).to.equal(14);
      expect(startingArray).to.include.members([1,2,3,4,6,7,8,9,12,13,14]);
      expect(startingArray[4]).to.be.NaN;
      expect(startingArray[9]).to.be.NaN;
      expect(startingArray[10]).to.be.NaN;
    });
  });
  describe(`2 : Modify ex2 ...`, function(){
    it(`returns a number`, function(){
      expect(typeof ex2([1,2,3,4,NaN])).to.equal('number');
    });
    it(`returns the provided numbers (less NaN) reversed and subtracted`, function(){
      expect(ex2([1,2,3,4,NaN])).to.equal(-2);
    });
    it(`did not alter the original array`, function(){
      expect(startingArray.length).to.equal(14);
      expect(startingArray).to.include.members([1,2,3,4,6,7,8,9,12,13,14]);
      expect(startingArray[4]).to.be.NaN;
      expect(startingArray[9]).to.be.NaN;
      expect(startingArray[10]).to.be.NaN;
    });
  });
  describe(`3 : Modify ex3 ...`, function(){
    it(`returns an array`, function(){
      expect(Array.isArray(ex3([NaN,2,4,1,3]))).to.be.true;
    });
    it(`sorts the values in ascending order and places NaN at the end`, function(){
      expect(ex3([NaN,2,4,1,3])[0]).to.equal(1);
      expect(ex3([NaN,2,4,1,3])[1]).to.equal(2);
      expect(ex3([NaN,2,4,1,3])[2]).to.equal(3);
      expect(ex3([NaN,2,4,1,3])[3]).to.equal(4);
      expect(ex3([NaN,2,4,1,3])[4]).to.be.NaN;
    });
    it(`did not alter the original array`, function(){
      expect(startingArray.length).to.equal(14);
      expect(startingArray).to.include.members([1,2,3,4,6,7,8,9,12,13,14]);
      expect(startingArray[4]).to.be.NaN;
      expect(startingArray[9]).to.be.NaN;
      expect(startingArray[10]).to.be.NaN;
    });
  });
});
