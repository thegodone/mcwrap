#### main
%$function_name_caps$ - $one_line_description$
@if $has_multi_line_description$=1
$multi_line_description$
@end if
%
% Syntax:  [$output_parameter_list$] = $function_name$($input_parameter_list$)
%
% Inputs:
@foreach input
%    $pname$ - $dtype$ ($dimensions$)
@end foreach input
%
% Outputs:
@foreach output
%    $pname$ - $dtype$ ($dimensions$)
@end foreach output
#### end