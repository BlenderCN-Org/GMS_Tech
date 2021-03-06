if(fragment_mode == FRAGMENT_OCCLUSION_SECOND_PASS)
{
  gl_FragColor = vec4(1.0);

  vec2 pixel = a_pixel*2.0;

  //float target_index = (out_TexCoord.y/pixel.y - 0.5 + pixel.x + out_TexCoord.x)/pixel.x;
  float target_index = (gl_FragCoord.y - 0.5) * 32.0 + gl_FragCoord.x + 0.5;
  //target_index = floor(target_index);

  if(target_index >= 20.0*20.0) return;

  float current_index = 0.0;

  for(vec2 leading_coord = vec2(1.0); leading_coord.y >= 0.0;)
  {
    vec4 leading_color = texture2D(gm_BaseTexture, leading_coord);
    if(leading_color != vec4(1.0))
    {
      current_index += 1.0;

      if(current_index == target_index)
      {
        gl_FragData[0] = leading_color; return;
      }
    }

    //next leading coord
    leading_coord.x -= a_pixel.x;
    if(leading_coord.x < 0.0) leading_coord = vec2(1.0, leading_coord.y - a_pixel.y);
  }
}
