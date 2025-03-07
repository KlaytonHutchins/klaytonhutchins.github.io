// binarySearch(5, test, bubbleSort);

var tstArr = testArray;
describe(`Array Lab Test Suite`, function() {
  it(`has a testArray with set values`, function() {
    expect(testArray).to.be.defined;
    expect(testArray).to.include.members([
      8,99,76,90,1009,6520,32,102,109,392,324,203,230,
      12,23,546,234,1231,5346,4235234,1230,989,34230,
      123,242,124356,13,2,3,1,5,68,545,34,62,56
    ])
  })
  describe(`1 : Write a function named 'linearSearch' ...`, function() {
    afterEach(function() {
      tstArr = testArray;
    });
    it(`there is a function named 'linearSearch'`, function() {
      expect(linearSearch).to.be.defined;
      expect(typeof linearSearch).to.equal('function');
    });
    it(`returns a number`, function() {
      expect(typeof linearSearch(1,[1,2,3])).to.equal('number');
    });
    it(`finds 989 in testArray at index 21`, function() {
      expect(linearSearch(989, tstArr)).to.equal(21);
    });
    it(`does not find 4 in testArray (returns -1)`, function() {
      expect(linearSearch(4, tstArr)).to.equal(-1);
    })
  });

  describe(`2 : Write a function named 'slice' ...`, function() {
    afterEach(function() {
      tstArr = [
        8,99,76,90,1009,6520,32,102,109,392,324,203,230,
        12,23,546,234,1231,5346,4235234,1230,989,34230,
        123,242,124356,13,2,3,1,5,68,545,34,62,56
       ];
    });
    it(`there is a function named 'slice'`, function() {
      expect(slice).to.be.defined;
      expect(typeof slice).to.equal('function');
    });
    it(`returns an array`, function() {
      expect(Array.isArray(slice(1,[3,2,1]))).to.be.true;
    });
    it(`slice returns [5, 68, 545, 34, 62, 56] when the first argument is 30`, function() {
      expect(slice(30,tstArr)).to.include.members([5, 68, 545, 34, 62, 56]);
      expect(slice(30,tstArr)).not.to.include.members([1,2,3]);
      expect(slice(30,tstArr).length).to.equal(6)
    });
  });
  describe(`3 : Write a function named 'includes' ...  `, function() {
    it(`there is a function named 'includes'`, function() {
      expect(includes).to.be.defined;
      expect(typeof includes).to.equal('function');
    });
    it(`returns a boolean`, function() {
      expect(typeof includes(1,[1,2,3])).to.equal('boolean');
    });
    it(`returns true when looking for 989 in testArray`, function() {
      expect(includes(989, tstArr)).to.be.true;
    });
    it(`returns false when looking for 4 in testArray`, function() {
      expect(includes(4, tstArr)).to.be.false;
    });
  });
  describe(`4 : Write a function named 'filter' ...  `, function() {
    it(`there is a function named 'filter'`, function() {
      expect(filter).to.be.defined;
      expect(typeof filter).to.equal('function');
    });
    it(`returns an array`, function() {
      expect(Array.isArray(filter(1,[3,2,1]))).to.be.true;
    });

    it(`returns an array of length 10 when passed 1 and the testArray`, function() {
      expect(filter(1,testArray).length).to.equal(10);
    });
    it(`returns an array containing [1009,102,109,12,1231,1230,123,124356,13,1]
      when passed 1 and the testArray`, function() {
        expect(filter(1,testArray)).to.include.members([1009,102,109,12,1231,1230,123,124356,13,1]);
    });
    it(`doesn't return 989 when passed 1 and the testArray`, function() {
      expect(filter(1,testArray)).not.to.include.members([989]);
    })
  });
});
