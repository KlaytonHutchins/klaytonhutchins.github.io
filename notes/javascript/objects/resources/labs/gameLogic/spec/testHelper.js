let hideTests = function() {
  $('#mocha').hide();
  $('#hide').text('Show Tests');
  $('#hide').off('click', hideTests);
  $('#hide').on('click', showTests);
};

let showTests = function() {
  $('#mocha').show();
  $('#hide').text('Hide Tests');
  $('#hide').off('click', showTests);
  $('#hide').on('click', hideTests);
};
