if(fragment_mode == FRAGMENT_OCCLUSION_FIRST_PASS)
{
  gl_FragColor = texture2D(gm_BaseTexture, out_TexCoord);
  if(gl_FragColor != vec4(1.0))
  for(vec2 leading_coord = out_TexCoord + vec2(a_pixel.x,0.0); leading_coord.y <= 1.0;)
  {
    if(texture2D(gm_BaseTexture, leading_coord) == gl_FragColor)
    {
      gl_FragColor = vec4(1.0);
      return;
    }

    leading_coord.x += a_pixel.x;
    if(leading_coord.x > 1.0) leading_coord = vec2(0.0, leading_coord.y + a_pixel.y);
  }
  return;
}
