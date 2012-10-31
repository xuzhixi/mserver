package format
[数据长度,数据]
-------------------------------------------------------------------


--------------------------------------------------------------------

<cmd>
	<cmd_login>
		<username></username>
		<alias></alias>	<!-- 可选 -->
		<tags>
			<tag></tag>
		</tags>
	</cmd_login>
</cmd>

<cmd>
	<cmd_send_all>
		content
	</cmd_send_all>
</cmd>

<cmd>
	<cmd_send>
		<peer></peer>	<!-- username or alias name -->
		<content></content>
	<cmd_send>
</cmd>

<cmd>
	<cmd_send_tags>
		<tag></tag>
		<content></content>
	</cmd_send_tags>
</cmd>
