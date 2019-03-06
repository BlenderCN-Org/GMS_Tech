if(vertex_mode == VERTEX_OCCLUSION_DRAW)
{
	out_Color = vec4(id, 1.0);
	out_TexCoord = vec2(0.0);
}
else
{
	out_Color = in_Color;

	if(dot(id, vec3(byte, byte*256.0, byte*256.0*256.0)) >= UNIFORM_BUFFER_WIDTH*UNIFORM_BUFFER_WIDTH)
	{
		gs = grayscale;
		col = color;
	}

	if(in_TexCoord == vec2(0.0))
	{
		if(out_Color == vec4(1.0))
			out_Color = vec4(col, 1.0);

		if(grayscale != 1.0)
		{
			vec4 intensity = (out_Color.rgba + out_Color.gbra + out_Color.brga)/3.0;
			out_Color = mix(intensity, out_Color, gs);
		}
	}
	out_TexCoord = in_TexCoord;
}