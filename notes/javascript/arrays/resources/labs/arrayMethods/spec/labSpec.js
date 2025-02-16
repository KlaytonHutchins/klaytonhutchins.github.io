describe(`Array Methods Test Suite`, function(){
  describe(`1 : Modify ex1 ...`, function(){
    it(`returns an array`, function(){
      expect(Array.isArray(ex1([1,2,3,4,NaN]))).to.be.true;
    });
    it(`removes NaN (converts it to a number)`, function(){
      expect(ex1([1,2,3,4,NaN]).length).to.equal(5);
      expect(ex1([1,2,3,4,NaN])).not.to.include.members([NaN]);
      expect(ex1([1,2,3,4,NaN])).to.include.members([5]);
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
    it(`returns an array`, function(){
      expect(Array.isArray(ex2([1,2,3,4,NaN]))).to.be.true;
    });
    it(`removes NaN (converts it to 0)`, function(){
      expect(ex2([1,2,3,4,NaN]).length).to.equal(5);
      expect(ex2([1,2,3,4,NaN])).not.to.include.members([NaN]);
      expect(ex2([1,2,3,4,NaN])).to.include.members([0]);
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
      expect(Array.isArray(ex3([1,2,3,4,5]))).to.be.true;
    });
    it(`rotates the array`, function(){
      expect(ex3([1,2,3,4,5],2)[0]).to.equal(3);
      expect(ex3([1,2,3,4,5],2)[1]).to.equal(4);
      expect(ex3([1,2,3,4,5],2)[2]).to.equal(5);
      expect(ex3([1,2,3,4,5],2)[3]).to.equal(1);
      expect(ex3([1,2,3,4,5],2)[4]).to.equal(2);
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
